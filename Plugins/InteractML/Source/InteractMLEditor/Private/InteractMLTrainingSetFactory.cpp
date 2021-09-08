//----
// InteractML - Interactive Machine Learning Plugin
// Copyright (c) 2021 Phoenix Perry and Rebecca Fiebrink
// Using the MIT License. https://github.com/Interactml
//----

//main
#include "InteractMLTrainingSetFactory.h"

//unreal

//module
#include "InteractMLTrainingSet.h"

//module editor


#define LOCTEXT_NAMESPACE "InteractML"

UInteractMLTrainingSetFactory::UInteractMLTrainingSetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UInteractMLTrainingSet::StaticClass();
}

UObject* UInteractMLTrainingSetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UInteractMLTrainingSet* NewObjectAsset = NewObject<UInteractMLTrainingSet>(InParent, Name, Flags | RF_Transactional);

	//ensure a guid is assigned
	NewObjectAsset->UpdateDerivedState();

	return NewObjectAsset;
}


#undef LOCTEXT_NAMESPACE

