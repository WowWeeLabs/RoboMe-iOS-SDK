//
//  RobotProtocal.h
//  RobotApp
//
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

/** RoboMeCommands.h contains enums for commands to the robot (RobotCommand enum) and response commands/events from robot (IncomingRobotCommand enum).
 
 Commands from the device to the Robot (RobotCommand enum):
 
    typedef enum {
        kRobot_PowerOff = 0x01,
        kRobot_RemoteControlOn = 0x02,
        kRobot_RemoteControlOff = 0x03,
        
        // Movement commands
        kRobot_Stop = 0x00,
        kRobot_MoveForwardSpeed1 = 0x04,
        kRobot_MoveForwardSpeed2 = 0x05,
        kRobot_MoveForwardSpeed3 = 0x06,
        kRobot_MoveForwardSpeed4 = 0x07,
        kRobot_MoveForwardSpeed5 = 0x08,
        kRobot_MoveForwardFastest = kRobot_MoveForwardSpeed1,
        kRobot_MoveForwardSlowest = kRobot_MoveForwardSpeed5,
        kRobot_MoveForward = kRobot_MoveForwardSpeed1,
        kRobot_MoveBackwardSpeed1 = 0x09,
        kRobot_MoveBackwardSpeed2 = 0x0A,
        kRobot_MoveBackwardSpeed3 = 0x0B,
        kRobot_MoveBackwardSpeed4 = 0x0C,
        kRobot_MoveBackwardSpeed5 = 0x0D,
        kRobot_MoveBackwardFastest = kRobot_MoveBackwardSpeed1, // Fastest movement speed
        kRobot_MoveBackwardSlowest = kRobot_MoveBackwardSpeed5, // Slowest movement speed
        kRobot_MoveBackward = kRobot_MoveBackwardSpeed1,
        
        kRobot_TurnRightSpeed1 = 0x0E,
        kRobot_TurnRightSpeed2 = 0x0F,
        kRobot_TurnRightSpeed3 = 0x10,
        kRobot_TurnRightSpeed4 = 0x11,
        kRobot_TurnRightSpeed5 = 0x12,
        
        kRobot_TurnLeftSpeed1 = 0x13,
        kRobot_TurnLeftSpeed2 = 0x14,
        kRobot_TurnLeftSpeed3 = 0x15,
        kRobot_TurnLeftSpeed4 = 0x16,
        kRobot_TurnLeftSpeed5 = 0x17,
        
        kRobot_HeadTiltAllDown = 0x18,
        kRobot_HeadTiltAllUp = 0x19,
        kRobot_HeadReset = 0x1A,
        
        kRobot_TurnLeft90Degrees = 0x1B,
        kRobot_TurnLeft180Degrees = 0x1C,
        kRobot_TurnLeft360Degrees = 0x1D,
        
        kRobot_TurnRight90Degrees = 0x1E,
        kRobot_TurnRight180Degrees = 0x1F,
        kRobot_TurnRight360Degrees = 0x20,
        
        kRobot_HeadTiltUp1 = 0x2C,
        kRobot_HeadTiltUp2 = 0x2E,
        kRobot_HeadTiltDown1 = 0x2D,
        kRobot_HeadTiltDown2 = 0x2F,
        kRobot_HeadTiltUp = kRobot_HeadTiltUp1,
        kRobot_HeadTiltDown = kRobot_HeadTiltDown1,
        kRobot_StopMCUCommands = 0x30,
        kRobot_ResumeMCUCommands = 0x31,
        kRobot_GetSensorStatus = 0x32,
        
        // Change LED Color
        // Note to change the color you need
        // to first send:
        // kRobot_HeartBeatOff & kRobot_ShowMoodOff
        kRobot_RGBHeartOff = 0x22,
        kRobot_RGBHeartWhite = 0x23,
        kRobot_RGBHeartRed = 0x24,
        kRobot_RGBHeartGreen = 0x25,
        kRobot_RGBHeartBlue = 0x26,
        kRobot_RGBHeartYellow = 0x27,
        kRobot_RGBHeartCyan = 0x28,
        kRobot_RGBHeartOrange = 0x29,
     
        // --- Getting status reports ---
        
        // Gets battery level
        kRobot_GetBatteryLevel = 0x2A,
        
        // Gets LED and remote status 
        kRobot_GetLEDAndRemoteStatus = 0x2B,
        
        // Gets mood level 1-15
        kRobot_GetMood = 0x33,
        
        //  Get direction game level
        kRobot_GetDirectionGameLevel = 0x35,
        
        //  Returns status for showMood, remoteMovement, appMode, heartBeat
        kRobot_GetGeneralStatus = 0x44,
        
        //  Returns status for remoteControl, edgeDetection, chestDetection
        kRobot_GetIRStatus = 0x47,
        
        //  Changes Mood
        kRobot_IncreaseMood = 0x37,
        kRobot_DecreaseMood = 0x38,
        kRobot_ResetMood = 0x39,
        
        //  Reset direction game level
        kRobot_ResetDirectionGame = 0x3B,
        
        // Resets EPROM settings
        kRobot_ResetRoboMe = 0x3C,
        
        // Enables/Disables movement from IR Remote
        kRobot_RemoteMovementOff = 0x3E,
        kRobot_RemoteMovementOn = 0x3F,
        
        // Enables/Disable permanent app mode
        // If permanent mode is on then the robot
        // will no longer a personality when the device is
        // unplugged
        kRobot_PermanentAppModeOff = 0x40,
        kRobot_PermanentAppModeOn = 0x41,
        
        // Turns off heart beat
        kRobot_HeartBeatOff = 0x42,
        kRobot_HeartBeatOn = 0x43,
        
        // Turns off showing the mood on the LED
        kRobot_ShowMoodOff = 0x45,
        kRobot_ShowMoodOn = 0x46,
        
        // Make the robot flinch
        kRobot_Flinch = 0x48,
        
        // Turn off/on edge detection
         This is stored on the EPROM so change persists
        kRobot_EdgeDetectOff = 0x49,
        kRobot_EdgeDetectOn = 0x4A,
        
        // Stops Robot sending commands apart from IR remote
        kRobot_StopMCUCommandsExceptTX = 0x4B,
        
        // Turn off/on chest detection
        // This is not stored on the EPROM so change does not persist
        kRobot_ChestDetectOff = 0x4C,
        kRobot_ChestDetectOn = 0x4D,
        
        // --- Robot command detection voltage ---
        // Shouldn't need to change this. It will effect the
        // volume required to send a command to the robot
        kRobot_GetDetectionVoltage = 0x4E,
        kRobot_SetDetectionVoltage2 = 0x50,
        kRobot_SetDetectionVoltage3 = 0x51,
        kRobot_SetDetectionVoltage4 = 0x52,
        kRobot_SetDetectionVoltage5 = 0x53,
        kRobot_SetDetectionVoltage6 = 0x54,
        kRobot_SetDetectionVoltage7 = 0x55,
        kRobot_SetDetectionVoltage8 = 0x56,
        kRobot_SetDetectionVoltageLvl9 = 0x57,
        kRobot_SetDetectionVoltageLvl10 = 0x58,
        kRobot_SetDetectionVoltageLvl11 = 0x59,
        kRobot_SetDetectionVoltageLvl12 = 0x5A,
        kRobot_SetDetectionVoltageLvl13 = 0x5B,
        kRobot_SetDetectionVoltageLvl14 = 0x5C,
        kRobot_SetDetectionVoltageLvl15 = 0x5D,
        
        kRobot_CommandsEnd,
        
        kRobot_TurnRightFastest = kRobot_TurnRightSpeed1,
        kRobot_TurnRightSlowest = kRobot_TurnRightSpeed5,
        kRobot_TurnRight = kRobot_TurnRightSpeed5,
        
        kRobot_TurnLeftFastest = kRobot_TurnLeftSpeed1,
        kRobot_TurnLeftSlowest = kRobot_TurnLeftSpeed5,
        kRobot_TurnLeft = kRobot_TurnLeftSpeed5,
        
        kRobot_ColorStart = kRobot_RGBHeartOff,
        kRobot_ColorEnd = kRobot_RGBHeartOrange
    } RobotCommand;

 Incoming Commands/Events from the Robot (IncomingRobotCommand enum):
 
    typedef enum {
        // Battery Level
        kRobotIncoming_Battery100 = 0x00,	//100% Battery Power
        kRobotIncoming_Battery80 = 0x01,	//80% Battery Power
        kRobotIncoming_Battery60 = 0x02,	//60% Battery Power
        kRobotIncoming_Battery40 = 0x03,	//40% Battery Power
        kRobotIncoming_Battery20 = 0x04,	//20% Battery Power
        kRobotIncoming_Battery10 = 0x05,	//10% Battery Power
        
        // Remote Buttons. Repeated every 2 seconds while button is held down.
        kRobotIncoming_ForwardBtnPressed = 0x10,
        kRobotIncoming_ForwardBtnReleased = 0x11,
        kRobotIncoming_BackwardBtnPressed = 0x12,
        kRobotIncoming_BackwardBtnReleased = 0x13,
        kRobotIncoming_RightBtnPressed = 0x14,
        kRobotIncoming_RightBtnReleased = 0x15,
        kRobotIncoming_LeftBtnPressed = 0x16,
        kRobotIncoming_LeftBtnReleased = 0x17,
        kRobotIncoming_HeadupBtnPressed = 0x18,
        kRobotIncoming_HeadupBtnReleased = 0x19,
        kRobotIncoming_HeaddownBtnPressed = 0x1A,
        kRobotIncoming_HeaddownBtnReleased = 0x1B,
        kRobotIncoming_StopBtnPressed = 0x1C,
        kRobotIncoming_StopBtnReleased = 0x1D,
        kRobotIncoming_SpeechBtnPressed = 0x1E,
        kRobotIncoming_SpeechBtnReleased = 0x1F,
        kRobotIncoming_L1BtnPressed = 0x20,
        kRobotIncoming_L1BtnReleased = 0x21,
        kRobotIncoming_L2BtnPressed = 0x22,
        kRobotIncoming_L2BtnReleased = 0x23,
        kRobotIncoming_L3BtnPressed = 0x24,
        kRobotIncoming_L3BtnReleased = 0x25,
        kRobotIncoming_R1BtnPressed = 0x26,
        kRobotIncoming_R1BtnReleased = 0x27,
        kRobotIncoming_R2BtnPressed = 0x28,
        kRobotIncoming_R2BtnReleased = 0x29,
        kRobotIncoming_R3BtnPressed = 0x2A,
        kRobotIncoming_R3BtnReleased = 0x2B,
        
        kRobotIncoming_FlinchDetected = 0x2C,
        kRobotIncoming_RobotConnected = 0x2D,
        
        kRobotIncoming_RemoteButtonsEnd,
        kRobotIncoming_CommandsEnd = kRobotIncoming_RemoteButtonsEnd,
        kRobotIncoming_RemoteButtonsStart = kRobotIncoming_ForwardBtnPressed,
        
        kRobotIncoming_BatteryStatusStart = kRobotIncoming_Battery100,
        kRobotIncoming_BatteryStatusEnd = kRobotIncoming_Battery10,
        
        kRobotIncoming_SensorStatusStart = 0x80, // inclusive
        kRobotIncoming_SesnorStatusEnd = 0x8F, // inclusive
        
        kRobotIncoming_MoodStart = 0x90,
        kRobotIncoming_MoodEnd = 0x9F,
        
        kRobotIncoming_DetectionVoltageStart = 0xA0,
        kRobotIncoming_DetectionVoltageEnd = 0xAF,
        
        kRobotIncoming_DirectionLevelStart = 0xB0,
        kRobotIncoming_DirectionLevelEnd = 0xBF,
        
        kRobotIncoming_LEDStatusStart = 0xC0,
        kRobotIncoming_LEDStatusEnd = 0xCF,
        
        kRobotIncoming_GeneralStatusStart = 0xD0,
        kRobotIncoming_GeneralStatusEnd = 0xDF,
        
        kRobotIncoming_IRStatusStart = 0xF0,
        kRobotIncoming_IRStatusEnd = 0xFF,
        
        kRobotIncoming_HandshakeSensorStatusStart = 0xE0,
        kRobotIncoming_HandshakeSensorStatusEnd = 0xEF
        
    } IncomingRobotCommand;

 */
@interface RoboMeCommands : NSObject
@end

// Commands from the device to the Robot */
typedef enum {
    kRobot_PowerOff = 0x01,
    kRobot_RemoteControlOn = 0x02,
    kRobot_RemoteControlOff = 0x03,
    
    // Movement commands */
    kRobot_Stop = 0x00,
    kRobot_MoveForwardSpeed1 = 0x04,
    kRobot_MoveForwardSpeed2 = 0x05,
    kRobot_MoveForwardSpeed3 = 0x06,
    kRobot_MoveForwardSpeed4 = 0x07,
    kRobot_MoveForwardSpeed5 = 0x08,
    kRobot_MoveForwardFastest = kRobot_MoveForwardSpeed1,
    kRobot_MoveForwardSlowest = kRobot_MoveForwardSpeed5,
    kRobot_MoveForward = kRobot_MoveForwardSpeed1,
    kRobot_MoveBackwardSpeed1 = 0x09,
    kRobot_MoveBackwardSpeed2 = 0x0A,
    kRobot_MoveBackwardSpeed3 = 0x0B,
    kRobot_MoveBackwardSpeed4 = 0x0C,
    kRobot_MoveBackwardSpeed5 = 0x0D,
    kRobot_MoveBackwardFastest = kRobot_MoveBackwardSpeed1, // Fastest movement speed
    kRobot_MoveBackwardSlowest = kRobot_MoveBackwardSpeed5, // Slowest movement speed
    kRobot_MoveBackward = kRobot_MoveBackwardSpeed1,
    
    kRobot_TurnRightSpeed1 = 0x0E,
    kRobot_TurnRightSpeed2 = 0x0F,
    kRobot_TurnRightSpeed3 = 0x10,
    kRobot_TurnRightSpeed4 = 0x11,
    kRobot_TurnRightSpeed5 = 0x12,
    
    kRobot_TurnLeftSpeed1 = 0x13,
    kRobot_TurnLeftSpeed2 = 0x14,
    kRobot_TurnLeftSpeed3 = 0x15,
    kRobot_TurnLeftSpeed4 = 0x16,
    kRobot_TurnLeftSpeed5 = 0x17,
    
    kRobot_HeadTiltAllDown = 0x18,
    kRobot_HeadTiltAllUp = 0x19,
    kRobot_HeadReset = 0x1A,

    kRobot_TurnLeft90Degrees = 0x1B,
    kRobot_TurnLeft180Degrees = 0x1C,
    kRobot_TurnLeft360Degrees = 0x1D,
    
    kRobot_TurnRight90Degrees = 0x1E,
    kRobot_TurnRight180Degrees = 0x1F,
    kRobot_TurnRight360Degrees = 0x20,

    kRobot_HeadTiltUp1 = 0x2C,
    kRobot_HeadTiltUp2 = 0x2E,
    kRobot_HeadTiltDown1 = 0x2D,
    kRobot_HeadTiltDown2 = 0x2F,
    kRobot_HeadTiltUp = kRobot_HeadTiltUp1,
    kRobot_HeadTiltDown = kRobot_HeadTiltDown1,
    kRobot_StopMCUCommands = 0x30,
    kRobot_ResumeMCUCommands = 0x31,
    kRobot_GetSensorStatus = 0x32,
    
    /** Change LED Color
        Note to change the color you need
        to first send:
        kRobot_HeartBeatOff & kRobot_ShowMoodOff */
    kRobot_RGBHeartOff = 0x22,
    kRobot_RGBHeartWhite = 0x23,
    kRobot_RGBHeartRed = 0x24,
    kRobot_RGBHeartGreen = 0x25,
    kRobot_RGBHeartBlue = 0x26,
    kRobot_RGBHeartYellow = 0x27,
    kRobot_RGBHeartCyan = 0x28,
    kRobot_RGBHeartOrange = 0x29,
    
    /** --- Getting status reports --- */
    
    /** Gets battery level */
    kRobot_GetBatteryLevel = 0x2A,
    
    /** Gets LED and remote status */
    kRobot_GetLEDAndRemoteStatus = 0x2B,
    
    /** Gets mood level 1-15 */
    kRobot_GetMood = 0x33,
    
    /**  Get direction game level */
    kRobot_GetDirectionGameLevel = 0x35,
    
    /**  Returns status for showMood, remoteMovement, appMode, heartBeat */
    kRobot_GetGeneralStatus = 0x44,
    
    /**  Returns status for remoteControl, edgeDetection, chestDetection */
    kRobot_GetIRStatus = 0x47,
    
    /**  Changes Mood */
    kRobot_IncreaseMood = 0x37,
    kRobot_DecreaseMood = 0x38,
    kRobot_ResetMood = 0x39,
    
    /**  Reset direction game level */
    kRobot_ResetDirectionGame = 0x3B,
    
    /** Resets EPROM settings */
    kRobot_ResetRoboMe = 0x3C,
    
    /** Enables/Disables movement from IR Remote */
    kRobot_RemoteMovementOff = 0x3E,
    kRobot_RemoteMovementOn = 0x3F,
    
    /** Enables/Disable permanent app mode
        If permanent mode is on then the robot
        will no longer a personality when the device is
        unplugged */
    kRobot_PermanentAppModeOff = 0x40,
    kRobot_PermanentAppModeOn = 0x41,
    
    /** Turns off heart beat */
    kRobot_HeartBeatOff = 0x42,
    kRobot_HeartBeatOn = 0x43,
    
    /** Turns off showing the mood on the LED */
    kRobot_ShowMoodOff = 0x45,
    kRobot_ShowMoodOn = 0x46,
    
    /** Make the robot flinch */
    kRobot_Flinch = 0x48,
    
    /** Turn off/on edge detection
        This is stored on the EPROM so change persists */
    kRobot_EdgeDetectOff = 0x49,
    kRobot_EdgeDetectOn = 0x4A,
    
    /** Stops Robot sending commands apart from IR remote */
    kRobot_StopMCUCommandsExceptTX = 0x4B,
    
    /** Turn off/on chest detection
        This is not stored on the EPROM so change does not persist */
    kRobot_ChestDetectOff = 0x4C,
    kRobot_ChestDetectOn = 0x4D,
        
    /** --- Robot command detection voltage --- */
    /** Shouldn't need to change this. It will effect the
        volume required to send a command to the robot */
    kRobot_GetDetectionVoltage = 0x4E,
    kRobot_SetDetectionVoltage2 = 0x50,
    kRobot_SetDetectionVoltage3 = 0x51,
    kRobot_SetDetectionVoltage4 = 0x52,
    kRobot_SetDetectionVoltage5 = 0x53,
    kRobot_SetDetectionVoltage6 = 0x54,
    kRobot_SetDetectionVoltage7 = 0x55,
    kRobot_SetDetectionVoltage8 = 0x56,
    kRobot_SetDetectionVoltageLvl9 = 0x57,
    kRobot_SetDetectionVoltageLvl10 = 0x58,
    kRobot_SetDetectionVoltageLvl11 = 0x59,
    kRobot_SetDetectionVoltageLvl12 = 0x5A,
    kRobot_SetDetectionVoltageLvl13 = 0x5B,
    kRobot_SetDetectionVoltageLvl14 = 0x5C,
    kRobot_SetDetectionVoltageLvl15 = 0x5D,
    
    kRobot_CommandsEnd,
    
    kRobot_TurnRightFastest = kRobot_TurnRightSpeed1,
    kRobot_TurnRightSlowest = kRobot_TurnRightSpeed5,
    kRobot_TurnRight = kRobot_TurnRightSpeed5, 
        
    kRobot_TurnLeftFastest = kRobot_TurnLeftSpeed1,
    kRobot_TurnLeftSlowest = kRobot_TurnLeftSpeed5,
    kRobot_TurnLeft = kRobot_TurnLeftSpeed5, 
    
    kRobot_ColorStart = kRobot_RGBHeartOff,
    kRobot_ColorEnd = kRobot_RGBHeartOrange
} RobotCommand;

typedef enum {
    /** Battery Level */
    kRobotIncoming_Battery100 = 0x00,	//100% Battery Power
    kRobotIncoming_Battery80 = 0x01,	//80% Battery Power
    kRobotIncoming_Battery60 = 0x02,	//60% Battery Power
    kRobotIncoming_Battery40 = 0x03,	//40% Battery Power
    kRobotIncoming_Battery20 = 0x04,	//20% Battery Power
    kRobotIncoming_Battery10 = 0x05,	//10% Battery Power
    
    /** Remote Buttons. Repeated every 2 seconds while button is held down. */
    kRobotIncoming_ForwardBtnPressed = 0x10,
    kRobotIncoming_ForwardBtnReleased = 0x11,
    kRobotIncoming_BackwardBtnPressed = 0x12,
    kRobotIncoming_BackwardBtnReleased = 0x13,
    kRobotIncoming_RightBtnPressed = 0x14,
    kRobotIncoming_RightBtnReleased = 0x15,
    kRobotIncoming_LeftBtnPressed = 0x16,
    kRobotIncoming_LeftBtnReleased = 0x17,
    kRobotIncoming_HeadupBtnPressed = 0x18,
    kRobotIncoming_HeadupBtnReleased = 0x19,
    kRobotIncoming_HeaddownBtnPressed = 0x1A,
    kRobotIncoming_HeaddownBtnReleased = 0x1B,
    kRobotIncoming_StopBtnPressed = 0x1C,
    kRobotIncoming_StopBtnReleased = 0x1D,
    kRobotIncoming_SpeechBtnPressed = 0x1E,
    kRobotIncoming_SpeechBtnReleased = 0x1F,
    kRobotIncoming_L1BtnPressed = 0x20,
    kRobotIncoming_L1BtnReleased = 0x21,
    kRobotIncoming_L2BtnPressed = 0x22,
    kRobotIncoming_L2BtnReleased = 0x23,
    kRobotIncoming_L3BtnPressed = 0x24,
    kRobotIncoming_L3BtnReleased = 0x25,
    kRobotIncoming_R1BtnPressed = 0x26,
    kRobotIncoming_R1BtnReleased = 0x27,
    kRobotIncoming_R2BtnPressed = 0x28,
    kRobotIncoming_R2BtnReleased = 0x29,
    kRobotIncoming_R3BtnPressed = 0x2A,
    kRobotIncoming_R3BtnReleased = 0x2B,
    
    kRobotIncoming_FlinchDetected = 0x2C,
    kRobotIncoming_RobotConnected = 0x2D,
    
    kRobotIncoming_RemoteButtonsEnd,
    kRobotIncoming_CommandsEnd = kRobotIncoming_RemoteButtonsEnd,
    kRobotIncoming_RemoteButtonsStart = kRobotIncoming_ForwardBtnPressed,
    
    kRobotIncoming_BatteryStatusStart = kRobotIncoming_Battery100,
    kRobotIncoming_BatteryStatusEnd = kRobotIncoming_Battery10,
    
    kRobotIncoming_SensorStatusStart = 0x80, // inclusive
    kRobotIncoming_SesnorStatusEnd = 0x8F, // inclusive
    
    kRobotIncoming_MoodStart = 0x90,
    kRobotIncoming_MoodEnd = 0x9F,
    
    kRobotIncoming_DetectionVoltageStart = 0xA0, 
    kRobotIncoming_DetectionVoltageEnd = 0xAF,
    
    kRobotIncoming_DirectionLevelStart = 0xB0,
    kRobotIncoming_DirectionLevelEnd = 0xBF,
    
    kRobotIncoming_LEDStatusStart = 0xC0,
    kRobotIncoming_LEDStatusEnd = 0xCF,
    
    kRobotIncoming_GeneralStatusStart = 0xD0,
    kRobotIncoming_GeneralStatusEnd = 0xDF,
    
    kRobotIncoming_IRStatusStart = 0xF0,
    kRobotIncoming_IRStatusEnd = 0xFF,
    
    kRobotIncoming_HandshakeSensorStatusStart = 0xE0,
    kRobotIncoming_HandshakeSensorStatusEnd = 0xEF
        
} IncomingRobotCommand;





