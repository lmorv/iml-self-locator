//----
// InteractML - University Of Arts London
//----

#pragma once

//unreal
#include "CoreMinimal.h"

//module
#include "InteractMLParameters.generated.h"

//general declarations


// wrapper for passing around parameters by value without copying the underlying collection object (lives in the context/actor)
//
USTRUCT(BlueprintType)
struct INTERACTML_API FInteractMLParameters
{
	GENERATED_USTRUCT_BODY()
	TSharedPtr<struct FInteractMLParameterCollection> Ptr;

	//ctors
	FInteractMLParameters(){}
	FInteractMLParameters(TSharedPtr<struct FInteractMLParameterCollection> ptr) : Ptr(ptr) {}
};

// InteractML parameter state snapshot, single sample/capture/frame of parameter values
// List of parameters with associated name/type/value
// In-memory use only for passing around in node graph
// NOTE: Not a UObject or USTRUCT, just a plain C++ struct
// NOTE: pass around graph via FInteractMLParameters wrapper (or just a TSharedPtr<struct FInteractMLParameterCollection>)
//
struct INTERACTML_API FInteractMLParameterCollection
{
	//type information
	//TArray<FString>  Names;
	//TArray<FName>    Types;

	//parameter value snapshot
	TArray<float>    Values;

	//accumulation cursor, i.e. which value we're adding next
	int              Cursor;

	
	//---- setup ----

	// completely clear out state
	void Clear();

	// start accumulation from first parameter again
	void Reset();

	//accumulation
	void Add(bool value);
	void Add(float value);
	void Add(int value);
	void Add(FVector2D value);
	void Add(FVector value);
	void Add(FQuat value);
	void Add(FLinearColor value);
	void Add(FColor value);
	

private:

	// replace/add a value at current position as needed
	//
	void AccumulateValue( float value )
	{
		if(Cursor < Values.Num())
		{
			Values[Cursor] = value;
		}
		else
		{
			Values.Add( value );
		}
		Cursor++;
	}
};