//----
// InteractML - University Of Arts London
//----

#pragma once

//unreal
#include "CoreMinimal.h"

//reactml
#include "classification.h"

//module
#include "InteractMLModel.h"
#include "InteractMLClassificationModel.generated.h"

//general declarations

// InteractML Model for running a Classification algorithm
//
UCLASS(BlueprintType)
class INTERACTML_API UInteractMLClassificationModel
	: public UInteractMLModel
{
	GENERATED_BODY()	
		
	//---- persistent state ----
	
	
	//---- transient/cached state ----
	TSharedPtr<classificationFloat> Model;
	
public:
	//---- constants ----
	
	// extension prefix for model data files
	static FString cExtensionPrefix;
	
	//---- access ----

	//---- operation ----
	virtual void ResetModelInstance() override;
	virtual modelSetFloat* GetModelInstance() const override { return Model.Get(); }
	
	//each type provides further qualifying extension prefix
	virtual FString GetSpecificExtensionPrefix() const override { return cExtensionPrefix; }
	

private:
	
};
