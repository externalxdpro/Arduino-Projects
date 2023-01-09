// Variables to set:
// rpmSpeed
// motor.MotorParam.MotorPolepairs
// motor.MotorParam.SensingMode
// motor.MotorParam.PI_Reg_P
// motor.MotorParam.PI_Reg_I

#include <IFX007T-Motor-Control.h>

#define DIRECTION  0
#define WEAKENING  0

uint16_t rpmSpeed = 800;

IFX007TMotorControl motor = IFX007TMotorControl();

void setup()
{
  Serial.begin(115200);

  motor.begin();
  motor.MotorParam.MotorPolepairs = 4;
  motor.MotorParam.SensingMode = 1;
  motor.MotorParam.PI_Reg_P = 0.01;
  motor.MotorParam.PI_Reg_I = 0.01;

  motor.configureBLDCMotor(motor.MotorParam);
}

void loop()
{
  motor.setHallBLDCmotorRPMspeed(DIRECTION, rpmSpeed, WEAKENING);

  if (Serial.available() > 0)
  {
    uint8_t in = Serial.read();
    if (in == '+') rpmSpeed += 200;
    if (in == '-') rpmSpeed -= 200;
    Serial.println("Current speed: " + (String) rpmSpeed);
  }
}
