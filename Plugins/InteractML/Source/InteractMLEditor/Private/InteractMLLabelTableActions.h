//----
// InteractML - Interactive Machine Learning Plugin
// Copyright (c) 2021 Phoenix Perry and Rebecca Fiebrink
// Using the MIT License. https://github.com/Interactml
//----

#pragma once

#include "AssetTypeActions_Base.h"
#include "Misc/EngineVersionComparison.h"


////////////////////////////// LABEL TABLE /////////////////////////////

// expose our label table asset type to various editor systems
//
class FInteractMLLabelTableActions : public FAssetTypeActions_Base
{
	uint32 RegisteredCategoryHandle;
public:
	
	FInteractMLLabelTableActions(uint32 InAssetCategory)
		: RegisteredCategoryHandle(InAssetCategory)
	{
#if UE_VERSION_OLDER_THAN(5,2,0) //nolonger needed, something somthing IAssetTools::IsAssetClassSupported
		SetSupported( true );
#endif
	}
	
	// IAssetTypeActions Implementation
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	//virtual void GetActions(const TArray<UObject*>& InObjects, struct FToolMenuSection& Section) override;
	virtual void OpenAssetEditor( const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>() ) override;
	// End IAssetTypeActions
	
};

