// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Ch3Project.h"
#include "Ch3ProjectBlock.h"
#include "Ch3ProjectBlockGrid.h"

ACh3ProjectBlock::ACh3ProjectBlock()
{
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> BlueMaterial;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> OrangeMaterial;
		FConstructorStatics()
			: PlaneMesh(TEXT("/Game/Puzzle/Meshes/PuzzleCube.PuzzleCube"))
			, BlueMaterial(TEXT("/Engine/TemplateResources/MI_Template_BaseBlue.MI_Template_BaseBlue"))
			, OrangeMaterial(TEXT("/Engine/TemplateResources/MI_Template_BaseOrange.MI_Template_BaseOrange"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	BlockMesh->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());
	BlockMesh->SetRelativeScale3D(FVector(1.f,1.f,0.25f));
	BlockMesh->SetRelativeLocation(FVector(0.f,0.f,25.f));
	BlockMesh->SetMaterial(0, ConstructorStatics.BlueMaterial.Get());
	BlockMesh->AttachTo(DummyRoot);
	BlockMesh->OnClicked.AddDynamic(this, &ACh3ProjectBlock::BlockClicked);
	BlockMesh->OnInputTouchBegin.AddDynamic(this, &ACh3ProjectBlock::OnFingerPressedBlock);

	// Save a pointer to the orange material
	OrangeMaterial = ConstructorStatics.OrangeMaterial.Get();
    BlueMaterial = ConstructorStatics.BlueMaterial.Get();
}

void ACh3ProjectBlock::BlockClicked(UPrimitiveComponent* ClickedComp)
{
    bIsActive = !bIsActive; // flip the value of bIsActive
    
    if(bIsActive) {
        BlockMesh->SetMaterial(0, OrangeMaterial);
    } else {
        BlockMesh->SetMaterial(0, BlueMaterial);
    }
    
    // Tell the Grid
    if(OwningGrid != NULL) {
        OwningGrid->AddScore();
    }
}


void ACh3ProjectBlock::OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	BlockClicked(TouchedComponent);
}
