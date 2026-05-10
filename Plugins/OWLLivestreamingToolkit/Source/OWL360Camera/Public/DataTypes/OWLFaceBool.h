// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "OWLFaceIndex.h"

/* Helper for handling on/off scenarios for faces */
struct FOWLFaceBool
{
public:
	FOWLFaceBool()
	{
		for (int i=0; i<6;i++)
		{
			Data[i] = true;
		}
	}
	FOWLFaceBool(const FOWLFaceBool& In)
	{
		for (int i=0; i<6; i++)
		{
			Data[i] = In[i];
		}
	}
	FOWLFaceBool(bool In)
	{
		for (int i=0; i<6;i++)
		{
			Data[i] = In;
		}
	}
	FOWLFaceBool(TArray<bool> In)
	{
		check(In.Num() ==6);
		for (int i = 0; i< 6; i++)
		{
			Data[i] = In[i];
		}
	}
	FOWLFaceBool(const bool(& In)[6])
	{
		for (int i = 0; i < 6; i++)
		{
			Data[i] = In[i];
		}
	}
	bool operator[](const int Index) const
	{
		ensureMsgf(Index >=0 && Index < 6, TEXT("Out of face range"));
		return Data[Index];
	}

	bool& operator[](const int Index)
	{
		ensureMsgf(Index >=0 && Index < 6, TEXT("Out of face range"));
		return Data[Index];
	}

	bool operator[](EOWL360FaceIndex Index) const
	{
		return Data[static_cast<int>(Index)];
	}

	bool& operator[](EOWL360FaceIndex Index)
	{
		return Data[static_cast<int>(Index)];
	}

	bool operator==(const FOWLFaceBool& Comparison) const
	{
		for (int i=0; i< 6; i++)
		{
			if (Data[i] != Comparison[i])
			{
				return false;
			}
		}
		return true;
	}
	void operator=(const bool In)
	{
		for (int i=0; i< 6; i++)
		{
			Data[i] = In;
		}
	}

	TArray<bool> ToArray() const
	{
		TArray<bool> Out;
		for (int i = 0; i< 6; i++)
		{
			Out.Add(Data[i]);
		}
		return Out;
	}

	FString ToString() const
	{
		FString Out = "[";
		for (int i = 0; i < Num; i++)
		{
			Out+= Data[i] ? "1,": "0,";
		}
		return Out + "]";
	}

static constexpr int Num = 6;

private:
	bool Data[6];
};


