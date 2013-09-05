//
//  RoboMeCommandHelper.h
//  RoboMe
//
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoboMeCommands.h"

typedef enum {
    kRobotSensor_EdgeDetect = 1,
    kRobotSensor_Chest20cmDetect = 2,
    kRobotSensor_Chest50cmDetect = 3,
    kRobotSensor_Chest100cmDetect = 4,
    kRobotSensor_FlinchDetect = 5,
    kRobotSensor_Handshake = 6,
    kRobotSensor_LowBattery = 7
} RobotSensor;

/** The LEDStatus class contains which color lights on the chest are turned on. */
@interface LEDStatus : NSObject
/** Red LED */
@property BOOL red;
/** Green LED */
@property BOOL green;
/** Blue LED */
@property BOOL blue;
@end

/** The SensorStatus class contains which sensors currently detect something.
 */
@interface SensorStatus : NSObject
/** Edge detection sensor. */
@property BOOL edge;
/** 100cm chest sensor. */
@property BOOL chest_100cm;
/** 50cm chest sensor. */
@property BOOL chest_50cm;
/** 20cm chest sensor. */
@property BOOL chest_20cm;
@end

/** The GeneralStatus class contains the status of settings such as if the current mood should be shown or if remote movement from the TX remote should be turned off.
 */
@interface GeneralStatus : NSObject
/** Shows current mood on chest LED. */
@property BOOL showMood;
/** If remote movement is off TX remote buttons will be ignored by the robot. */
@property BOOL remoteMovement;
/** If permanent app mode is on then the robot will no longer switch over to the default behavour/personality when the phone is unplugged. */
@property BOOL appMode;
/** Heatbeat pulses the chest LED. */
@property BOOL heartBeat;
@end

/** The IRStatus class contains the on/off status of the IR sensors including
 the IR receiver for remote control, edge detection, and the chest sensor.
 If a sensor is off changes or related events will not be sent to the phone/device.
 
 Note the SensorStatus class gives you whether or not the sensor detects something.
 */
@interface IRStatus : NSObject
/** Indicates whether TX remote control events like button presses should be sent to the phone/device. */
@property BOOL remoteControl;
/** Indicates whether edge detection on the robot is on or off. If edge detection is off it will not prevent the robot from moving off a edge. */
@property BOOL edgeDetection;
/** Indicates whether chest sensor on the robot is on or off. If chest detection is off then it will not prevent the robot from moving into a obstacle.  */
@property BOOL chestDetection;
@end

/** The RoboMeCommandHelper class provides useful methods to help classify and read incoming commands from the Robot.
 
 Many incoming commands from the robot can be directly compared to the enum int value however some commands like status reports need to be broken
 down and read in. 
 
 For example, if a sensor status is received from the robot you first need to check if it is a sensor status using isSensorStatus method then you can read the sensor status using readSensorStatus method.
 */
@interface RoboMeCommandHelper : NSObject

/** Reads LED status from incoming Robot command.
 
 @param command Command to read from.
 
 @return LEDStatus.
 */
+ (LEDStatus *)readLEDStatus: (IncomingRobotCommand)command;

/** Reads sensor status report from incoming Robot command.
 
 @param command Command to read from.
 
 @return SensorStatus.
 */
+ (SensorStatus *)readSensorStatus: (IncomingRobotCommand)command;

/** Reads General status report from incoming Robot command.
 
 @param command Command to read from.
 
 @return GeneralStatus.
 */
+ (GeneralStatus *)readGeneralStatus: (IncomingRobotCommand)command;

/** Reads IR status report from incoming Robot command.
 
 @param command Command to read from.
 
 @return IRStatus.
 */
+ (IRStatus *)readIRStatus: (IncomingRobotCommand)command;

/** Reads handshake status from incoming Robot command.
 
 @param command Command to read from.
 
 @return Number times hand has been shaken value 0 = 1 up/down, 1 = 4 up/down, 2 = 7 up/down, 3 = 10 up/down, etc.
 */
+ (int)readHandshakeStatus: (IncomingRobotCommand)command;

/** Reads detection voltage from incoming Robot command.
 
 @param command Command to read from.
 
 @return Detection voltage.
 */
+ (int)readDetectionVoltage: (IncomingRobotCommand)command;

/** Reads 4 bit value from end from incoming Robot command.
 
 Note this is used to get the mood and direction game values.
 
 @param command Command to read from.
 
 @return Int value from 0-16.
 */
+ (int)read4BitValue: (IncomingRobotCommand)command;

/**---------------------------------------------------------------------------------------
 * @name Classify type of incomming command
 *  ---------------------------------------------------------------------------------------
 */

/** Given command is a battery status.
 
 @param command Command to check.
 
 @return command is battery status.
 */
+ (BOOL)isBatteryStatus: (IncomingRobotCommand)command;

/** Given command is a button press on the remote.
 
 @param command Command to check.
 
 @return command is a remote button press.
 */
+ (BOOL)isRemoteButton: (IncomingRobotCommand)command;

/** Given command is a sensor status.
 
 Note use readSensorStatus method to read the sensor states.
 
 @param command Command to check.
 
 @return command is a sensor status.
 */
+ (BOOL)isSensorStatus: (IncomingRobotCommand)command;

/** Given command is an LED status.
 
 Note use readLEDStatus method to read the LED colors.
 
 @param command Command to check.
 
 @return command is an LED status.
 */
+ (BOOL)isLEDStatus: (IncomingRobotCommand)command;

/** Given command is the mood value.
 
 Note use read4BitValue method to read mood value.
 
 @param command Command to check.
 
 @return command is a mood value.
 */
+ (BOOL)isMoodValue: (IncomingRobotCommand)command;

/** Given command is the direction game level.
 
 Note use read4BitValue method to read mood value.
 
 @param command Command to check.
 
 @return command is the direction game level.
 */
+ (BOOL)isDirectionGameLevel: (IncomingRobotCommand)command;

/** Given command is a general status.
 
 Note use readGeneralStatus to get the values for GeneralStatus.
 
 @param command Command to check.
 
 @return command is a general status.
 */
+ (BOOL)isGeneralStatus: (IncomingRobotCommand)command;

/** Given command is an IR status.
 
 Note use readIRStatus to get the values for IRStatus.
 
 @param command Command to check.
 
 @return command is an IR status.
 */
+ (BOOL)isIRStatus: (IncomingRobotCommand)command;

/** Given command is a Handshake status.
 
 Note use readHandshakeStatus to get the number of times hand has been shaken.
 
 @param command Command to check.
 
 @return command is an Handshake status.
 */
+ (BOOL)isHandshakeStatus: (IncomingRobotCommand)command;

/** Given command is the detection voltage.
 
 Note use readDetectionVoltage to read the detection voltage.
 
 @param command Command to check.
 
 @return command is the detection voltage.
 */
+ (BOOL)isDetectionVoltage: (IncomingRobotCommand)command;

/**---------------------------------------------------------------------------------------
 * @name Conversion Helpers
 *  ---------------------------------------------------------------------------------------
 */

/** Converts robot command enum value to string.
 
 @param command RobotCommand to convert.
 
 @return Command as a readable string. */
+ (NSString *)robotCommandToString: (RobotCommand)command;

/** Converts incoming robot command enum value to string.
 
 @param command IncomingRobotCommand to convert.
 
 @return Command as a readable string. */
+ (NSString *)incomingRobotCommandToString: (IncomingRobotCommand)command;

/** Converts robot sensor enum value to string.
 
 @param robotSensor RobotSensor to convert.
 
 @return RobotSensor as a readable string. */
+ (NSString *)robotSensorToString: (RobotSensor)robotSensor;

/** Convert int to binary string.
 
 @param decimal Int to convert.
 
 @return Binary string.
 */
+ (NSString *)intToBinaryString: (int)decimal;

/** Convert int to 2 digit hex string.
 
 @param command Int to convert.
 
 @return 2 digit hex string.
 */
+ (NSString *)intTo2DigitHexString: (int)command;

/** Convert hex string to int.
 
 @param hexString Hex string e.g. "0x04".
 
 @return int value of hex string.
 */
+ (int)hexStringToInt: (NSString *)hexString;

@end
