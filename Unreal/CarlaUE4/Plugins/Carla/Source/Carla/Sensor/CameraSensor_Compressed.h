// Ree change:2.10.2019 @RH New Sensor class 
//

#pragma once

#include "Carla/Sensor/ShaderBasedSensor.h"

#include "Carla/Actor/ActorDefinition.h"

#include "CameraSensor_Compressed.generated.h"

/// Sensor .
UCLASS()
class CARLA_API ACameraSensor_Compressed : public AShaderBasedSensor
{
    GENERATED_BODY()

public:

    static FActorDefinition GetSensorDefinition();

    ACameraSensor_Compressed(const FObjectInitializer &ObjectInitializer);
 //   void Set(const FActorDescription &ActorDescription) override;

protected:

//  float m_jpgComp;
    void Tick(float DeltaTime) override;
};
