//----
// InteractML - Interactive Machine Learning Plugin
// Copyright (c) 2021 Phoenix Perry and Rebecca Fiebrink
// Using the MIT License. https://github.com/Interactml
//----

#pragma once

//unreal

//module
#include "InteractMLTrainingSetNode.h"
#include "InteractMLTrainingSetSnapshotNode.generated.h"

//general declarations

// Training set specialisation for single parameter set recording
//
UCLASS()
class INTERACTMLSCRIPTING_API UInteractMLTrainingSetSnapshotNode : public UInteractMLTrainingSetNode
{
	GENERATED_BODY()
		
public:
		
private:
		
protected:		

	//~ Begin training-set specific overrides
	virtual FText GetTrainingSetName() const override;
	virtual FText GetTrainingSetDescription() const override;
	virtual FText GetTrainingSetTooltip() const override;
	virtual FText GetRecordPinTooltip() const override;
	virtual FName GetRecordFunctionName() const override;
	//~ End training-set specific overrides
	
private:		
		
};