// Ree change:2.10.2019 @RH New Sensor class 

#include "Carla.h"
#include "Carla/Sensor/CameraSensor_Compressed.h"

#include "Carla/Sensor/PixelReader.h"

FActorDefinition ACameraSensor_Compressed::GetSensorDefinition()
{
    return UActorBlueprintFunctionLibrary::MakeCameraDefinition(TEXT("rgb_comp"));
/*
    auto definition = UActorBlueprintFunctionLibrary::MakeCameraDefinition(TEXT("rgb_comp"));

    FActorVariation compression;
    compression.Id = TEXT("jpg_comp");
    compression.Type = EActorAttributeType::Float;
    compression.RecommendedValues = { TEXT("80")};
    compression.bRestrictToRecommended = false;
    definition.Variations.Append( {compression});

    return definition;
    */
}

ACameraSensor_Compressed::ACameraSensor_Compressed(const FObjectInitializer &ObjectInitializer)
  : Super(ObjectInitializer)
{
  EnablePostProcessingEffects(true);

/*
    LoadPostProcessingMaterial(
#if PLATFORM_LINUX
      TEXT("Material'/Carla/PostProcessingMaterials/DepthEffectMaterial_GLSL.DepthEffectMaterial_GLSL'")
#else
      TEXT("Material'/Carla/PostProcessingMaterials/DepthEffectMaterial.DepthEffectMaterial'")
#endif
  ); // LoadPostProcessingMaterial
  */
}

void ACameraSensor_Compressed::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
  // Pushing the image data in the Render Thread to the stream buffer
  FPixelReader::SendPixelsInRenderThread(*this);
}

/*
void ACameraSensor_Compressed::Set(const FActorDescription &Description)
{
  Super::Set(Description);

  m_jpgComp = UActorBlueprintFunctionLibrary::RetrieveActorAttributeToFloat(
      "jpg_comp",
      Description.Variations,
      80.0f);

}
*/