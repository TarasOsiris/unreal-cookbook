// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTarasMeshComponent.h"
#include "DynamicMeshBuilder.h"

class FMyVertexBuffer final : public FVertexBuffer
{
public:
	TArray<FVector> Vertices;

	virtual void InitRHI() override
	{
		FRHIResourceCreateInfo CreateInfo;
		VertexBufferRHI = RHICreateVertexBuffer(Vertices.Num() * sizeof(FVector), BUF_Static, CreateInfo);
		void* VertexBufferData = RHILockVertexBuffer(VertexBufferRHI, 0, Vertices.Num() * sizeof(FVector), RLM_WriteOnly);
		FMemory::Memcpy(VertexBufferData, Vertices.GetData(), Vertices.Num() * sizeof(FVector));
		RHIUnlockVertexBuffer(VertexBufferRHI);
	}
};

class FMyIndexBuffer final : public FIndexBuffer
{
public:
	TArray<int32> Indices;

	virtual void InitRHI() override
	{
		FRHIResourceCreateInfo CreateInfo;
		IndexBufferRHI = RHICreateIndexBuffer(sizeof(int32), Indices.Num() * sizeof(int32), BUF_Static, CreateInfo);
		void* Buffer = RHILockIndexBuffer(IndexBufferRHI, 0, Indices.Num() * sizeof(int32), RLM_WriteOnly);
		FMemory::Memcpy(Buffer, Indices.GetData(), Indices.Num() * sizeof(int32));
		RHIUnlockIndexBuffer(IndexBufferRHI);
	}
};

class FMySceneProxy : public FPrimitiveSceneProxy
{
public:
	FMySceneProxy(UMyTarasMeshComponent* Component) : FPrimitiveSceneProxy(Component), TheMaterial(Component->TheMaterial), Indices(Component->Indices)
	{
		VertexBuffer = FMyVertexBuffer();
		IndexBuffer = FMyIndexBuffer();

		for (FVector Vertex : Component->Vertices)
		{
			Vertices.Add(FDynamicMeshVertex(Component->GetComponentLocation() + Vertex));
		}

		for (uint32 Index : Component->Indices)
		{
			Indices.Add(Index);
		}
	}

	UPROPERTY()
	UMaterial* TheMaterial;

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		FPrimitiveViewRelevance Result;
		Result.bDynamicRelevance = true;
		Result.bDrawRelevance = true;
		Result.bNormalTranslucency = true;
		return Result;
	}

	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const override
	{
		for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
		{
			FDynamicMeshBuilder MeshBuilder(ERHIFeatureLevel::ES3_1);
			if (Vertices.Num() == 0)
			{
				return;
			}
			MeshBuilder.AddVertices(Vertices);
			MeshBuilder.AddTriangles(Indices);
			const FColoredMaterialRenderProxy* MaterialRenderProxy = new FColoredMaterialRenderProxy(TheMaterial->GetRenderProxy(), FLinearColor::Gray);
			MeshBuilder.GetMesh(FMatrix::Identity, MaterialRenderProxy, GetDepthPriorityGroup(Views[ViewIndex]), true, true, ViewIndex, Collector);
		}
	}

	virtual ~FMySceneProxy() override
	{
	}

	virtual uint32 GetMemoryFootprint() const override
	{
		return sizeof(*this);
	}

	virtual SIZE_T GetTypeHash() const override
	{
		return 31;
	}

	virtual void OnTransformChanged() override
	{
		VertexBuffer.ReleaseResource();
		IndexBuffer.ReleaseResource();
	}

private:
	TArray<FDynamicMeshVertex> Vertices;
	TArray<uint32> Indices;
	FMyVertexBuffer VertexBuffer;
	FMyIndexBuffer IndexBuffer;
};

UMyTarasMeshComponent::UMyTarasMeshComponent()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial'"));
	if (Material.Object != nullptr)
	{
		TheMaterial = Material.Object;
	}
	Vertices.Add(FVector(10, 0, 0));
	Vertices.Add(FVector(0, 10, 0));
	Vertices.Add(FVector(0, 0, 10));
	Indices.Add(0);
	Indices.Add(1);
	Indices.Add(2);
}

FPrimitiveSceneProxy* UMyTarasMeshComponent::CreateSceneProxy()
{
	FPrimitiveSceneProxy* Proxy = new FMySceneProxy(this);
	return Proxy;
}
