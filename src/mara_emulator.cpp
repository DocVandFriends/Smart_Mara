#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Timer.h>
#include <SoftwareSerial.h>

char *output[] = {
"0,0,0,0,0,0",                //machine is OFF
"0,0,0,0,0,0",
"0,0,0,0,0,0",
"0,0,0,0,0,0",
"0,0,0,0,0,0",
"0,0,0,0,0,0",
"0,0,0,0,0,0",
"C1.23,050,140,043,1191,1",   //machine is switched ON
"C1.23,050,140,042,1186,1",
"C1.23,051,140,041,1181,1",
"C1.23,051,140,040,1176,1",
"C1.23,052,140,040,1170,1",
"C1.23,054,140,039,1165,1",
"C1.23,055,140,039,1160,1",
"C1.23,057,140,039,1155,1",
"C1.23,058,140,038,1150,1",
"C1.23,060,140,038,1144,1",
"C1.23,061,140,038,1139,1",
"C1.23,063,140,038,1134,1",
"C1.23,064,140,038,1129,1",
"C1.23,066,140,038,1124,1",
"C1.23,067,140,038,1118,1",
"C1.23,069,140,038,1113,1",
"C1.23,070,140,038,1108,1",
"C1.23,072,140,038,1103,1",
"C1.23,074,140,038,1098,1",
"C1.23,075,140,038,1092,0",
"C1.23,077,140,038,1087,1",
"C1.23,078,140,038,1082,1",
"C1.23,079,140,039,1077,0",
"C1.23,080,140,039,1072,0",
"C1.23,081,140,039,1066,1",
"C1.23,082,140,039,1061,1",
"C1.23,085,140,039,1056,0",
"C1.23,085,140,039,1051,1",
"C1.23,085,140,040,1046,1",
"C1.23,086,140,040,1040,0",
"C1.23,087,140,040,1035,1",
"C1.23,088,140,040,1030,0",
"C1.23,089,140,041,1025,0",
"C1.23,089,140,041,1020,1",
"C1.23,090,140,041,1014,0",
"C1.23,091,140,041,1009,1",
"C1.23,091,140,042,1004,0",
"C1.23,091,140,042,0999,1",
"C1.23,091,140,042,0994,1",
"C1.23,092,140,043,0988,0",
"C1.23,093,140,043,0983,1",
"C1.23,093,140,043,0978,1",
"C1.23,094,140,044,0973,0",
"C1.23,094,140,044,0968,1",
"C1.23,094,140,044,0962,1",
"C1.23,094,140,045,0957,0",
"C1.23,095,140,045,0952,1",
"C1.23,095,140,045,0947,1",
"C1.23,096,140,046,0942,0",
"C1.23,096,140,046,0936,1",
"C1.23,097,140,046,0931,1",
"C1.23,097,140,047,0926,0",
"C1.23,097,140,047,0921,1",
"C1.23,098,140,048,0916,0",
"C1.23,099,140,048,0910,1",
"C1.23,099,140,048,0905,1",
"C1.23,100,140,049,0900,0",
"C1.23,100,140,049,0895,1",
"C1.23,100,140,050,0890,0",
"C1.23,101,140,050,0884,1",
"C1.23,101,140,050,0879,1",
"C1.23,102,140,051,0874,0",
"C1.23,102,140,051,0869,1",
"C1.23,102,140,052,0864,0",
"C1.23,103,140,052,0858,1",
"C1.23,103,140,053,0853,1",
"C1.23,104,140,053,0848,0",
"C1.23,104,140,053,0843,1",
"C1.23,105,140,054,0838,0",
"C1.23,105,140,054,0832,1",
"C1.23,106,140,055,0827,1",
"C1.23,107,140,055,0822,1",
"C1.23,107,140,055,0817,1",
"C1.23,108,140,056,0812,1",
"C1.23,109,140,056,0806,1",
"C1.23,110,140,057,0801,1",
"C1.23,111,140,057,0796,1",
"C1.23,112,140,058,0791,1",
"C1.23,113,140,058,0786,1",
"C1.23,113,140,059,0780,1",
"C1.23,114,140,059,0775,1",
"C1.23,115,140,059,0770,1",
"C1.23,116,140,060,0765,1",
"C1.23,116,140,060,0760,1",
"C1.23,117,140,061,0754,1",
"C1.23,118,140,061,0749,1",
"C1.23,119,140,062,0744,1",
"C1.23,119,140,062,0739,1",
"C1.23,120,140,063,0734,1",
"C1.23,121,140,063,0728,1",
"C1.23,121,140,064,0723,1",
"C1.23,122,140,064,0718,1",
"C1.23,123,140,065,0713,1",
"C1.23,124,140,066,0708,1",
"C1.23,124,140,066,0702,1",
"C1.23,125,140,067,0697,1",
"C1.23,126,140,067,0692,1",
"C1.23,126,140,068,0687,1",
"C1.23,127,140,069,0682,1",
"C1.23,128,140,069,0676,1",
"C1.23,129,140,070,0671,1",
"C1.23,129,140,070,0666,1",
"C1.23,130,140,071,0661,1",
"C1.23,131,140,071,0656,1",
"C1.23,132,140,072,0650,1",
"C1.23,132,140,073,0645,1",
"C1.23,133,140,073,0640,1",
"C1.23,134,140,074,0635,1",
"C1.23,135,140,074,0630,1",
"C1.23,135,140,075,0624,1",
"C1.23,136,140,075,0619,1",
"C1.23,137,140,076,0614,1",
"C1.23,137,140,077,0609,1",
"C1.23,138,140,077,0604,1",
"C1.23,139,140,078,0598,1",
"C1.23,140,140,078,0593,0",
"C1.23,140,140,079,0588,0",
"C1.23,140,140,080,0583,0",
"C1.23,140,140,080,0578,0",
"C1.23,139,140,081,0572,1",
"C1.23,140,140,081,0567,0",
"C1.23,140,140,082,0562,0",
"C1.23,140,140,083,0557,0",
"C1.23,140,140,083,0552,0",
"C1.23,139,140,084,0546,1",
"C1.23,140,140,084,0541,0",
"C1.23,140,140,085,0536,0",
"C1.23,140,140,085,0531,0",
"C1.23,140,140,086,0526,0",
"C1.23,140,140,086,0520,0",
"C1.23,139,126,091,0000,0",
"C1.23,139,126,091,0000,0",
"C1.23,139,126,091,0000,0",
"C1.23,139,126,091,0000,0",
"C1.23,138,126,092,0000,0",
"C1.23,138,126,092,0000,0",
"C1.23,138,126,092,0000,0",
"C1.23,138,126,093,0000,0",
"C1.23,137,126,093,0000,0",
"C1.23,137,126,093,0000,0",
"C1.23,137,126,094,0000,0",
"C1.23,137,126,094,0000,0",
"C1.23,137,126,094,0000,0",
"C1.23,137,126,094,0000,0",
"C1.23,137,126,094,0000,0",
"C1.23,137,126,094,0000,0",
"C1.23,136,126,095,0000,0",
"C1.23,136,126,095,0000,0",
"C1.23,136,126,095,0000,0",
"C1.23,136,126,095,0000,0",
"C1.23,136,126,095,0000,0",
"C1.23,136,126,095,0000,0",
"C1.23,136,126,096,0000,0",
"C1.23,135,126,096,0000,0",
"C1.23,135,126,096,0000,0",
"C1.23,135,126,096,0000,0",
"C1.23,135,126,096,0000,0",
"C1.23,135,126,096,0000,0",
"C1.23,135,126,096,0000,0",
"C1.23,135,126,096,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,134,126,097,0000,0",
"C1.23,133,126,097,0000,0",
"C1.23,133,126,097,0000,0",
"C1.23,133,126,097,0000,0",
"C1.23,133,126,098,0000,0",
"C1.23,133,126,098,0000,0",
"C1.23,133,126,098,0000,0",
"C1.23,133,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,132,126,098,0000,0",
"C1.23,131,126,098,0000,0",
"C1.23,131,126,098,0000,0",
"C1.23,131,126,098,0000,0",
"C1.23,131,126,098,0000,0",
"C1.23,131,126,098,0000,0",
"C1.23,131,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,130,126,098,0000,0",
"C1.23,129,126,098,0000,0",
"C1.23,129,126,098,0000,0",
"C1.23,129,126,098,0000,0",
"C1.23,129,126,098,0000,0",
"C1.23,129,126,099,0000,0",
"C1.23,129,126,099,0000,0",
"C1.23,129,126,099,0000,0",
"C1.23,129,126,099,0000,0",
"C1.23,128,126,099,0000,0",
"C1.23,128,126,099,0000,0",
"C1.23,128,126,098,0000,0",
"C1.23,128,126,098,0000,0",
"C1.23,128,126,098,0000,0",
"C1.23,128,126,098,0000,0",
"C1.23,128,126,098,0000,0",
"C1.23,128,126,098,0000,0",
"C1.23,127,126,098,0000,0",
"C1.23,127,126,098,0000,0",
"C1.23,127,126,098,0000,0",
"C1.23,127,126,098,0000,0",
"C1.23,127,126,098,0000,0",
"C1.23,127,126,098,0000,0",
"C1.23,127,126,098,0000,0",
"C1.23,126,126,098,0000,0",
"C1.23,126,126,098,0000,0",
"C1.23,126,126,098,0000,0",
"C1.23,126,126,098,0000,0",
"C1.23,126,126,098,0000,0",
"C1.23,126,126,098,0000,0",
"C1.23,126,126,098,0000,0",
"C1.23,126,126,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,125,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,124,112,098,0000,0",
"C1.23,123,112,098,0000,0",
"C1.23,123,112,098,0000,0",
"C1.23,123,112,098,0000,0",
"C1.23,123,112,098,0000,0",
"C1.23,123,112,098,0000,0",
"C1.23,123,112,098,0000,0",
"C1.23,123,112,098,0000,0",
"C1.23,123,112,098,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,124,087,0000,1",
"C1.23,120,124,087,0000,1",
"C1.23,121,124,088,0000,1",
"C1.23,122,124,088,0000,1",
"C1.23,123,124,089,0000,1",
"C1.23,123,124,089,0000,1",
"C1.23,124,124,090,0000,1",
"C1.23,125,124,090,0000,1",
"C1.23,126,126,091,0000,0",
"C1.23,126,126,091,0000,0",
"C1.23,126,126,091,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,125,112,092,0000,1",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,093,0000,0",
"C1.23,125,112,093,0000,1",
"C1.23,125,112,093,0000,1",
"C1.23,126,126,093,0000,0",
"C1.23,127,126,093,0000,0",
"C1.23,127,126,093,0000,0",
"C1.23,126,126,093,0000,0",
"C1.23,126,126,094,0000,0",
"C1.23,126,126,094,0000,0",
"C1.23,126,126,094,0000,0",
"C1.23,126,126,094,0000,0",
"C1.23,126,126,094,0000,0",
"C1.23,126,126,094,0000,0",
"C1.23,126,126,094,0000,0",
"C1.23,125,112,095,0000,0",
"C1.23,125,112,095,0000,0",
"C1.23,125,112,095,0000,0",
"C1.23,125,112,095,0000,0",
"C1.23,125,112,095,0000,0",
"C1.23,125,112,095,0000,0",
"C1.23,125,112,095,0000,0",
"C1.23,125,112,095,0000,0",
"C1.23,125,112,096,0000,0",
"C1.23,125,112,096,0000,0",
"C1.23,125,112,096,0000,0",
"C1.23,125,112,096,0000,0",
"C1.23,125,112,096,0000,0",
"C1.23,125,112,096,0000,0",
"C1.23,124,112,096,0000,0",
"C1.23,124,112,096,0000,0",
"C1.23,124,112,096,0000,0",
"C1.23,124,112,096,0000,0",
"C1.23,124,112,096,0000,0",
"C1.23,124,112,097,0000,0",
"C1.23,124,112,097,0000,0",
"C1.23,124,112,097,0000,0",
"C1.23,124,112,097,0000,0",
"C1.23,124,112,097,0000,0",
"C1.23,124,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,123,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,122,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,121,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,120,112,097,0000,0",
"C1.23,119,112,097,0000,0",
"C1.23,119,112,097,0000,0",
"C1.23,119,112,097,0000,0",
"C1.23,119,112,097,0000,0",
"C1.23,119,112,097,0000,0",
"C1.23,119,112,097,0000,0",
"C1.23,119,112,097,0000,0",
"C1.23,119,112,097,0000,0",
"C1.23,119,112,096,0000,0",
"C1.23,119,112,096,0000,0",
"C1.23,119,112,096,0000,0",
"C1.23,119,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,118,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,117,112,096,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,116,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,095,0000,0",
"C1.23,115,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,114,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,094,0000,0",
"C1.23,113,112,093,0000,0",
"C1.23,113,112,093,0000,0",
"C1.23,113,112,093,0000,0",
"C1.23,112,112,093,0000,0",
"C1.23,112,112,093,0000,0",
"C1.23,112,112,093,0000,0",
"C1.23,112,112,093,0000,0",
"C1.23,112,112,093,0000,1",
"C1.23,112,112,093,0000,0",
"C1.23,112,112,093,0000,0",
"C1.23,112,112,093,0000,0",
"C1.23,113,112,093,0000,0",
"C1.23,113,112,093,0000,1",
"C1.23,113,112,093,0000,0",
"C1.23,113,112,093,0000,1",
"C1.23,113,112,093,0000,0",
"C1.23,114,112,093,0000,0",
"C1.23,114,112,093,0000,1",
"C1.23,115,112,093,0000,0",
"C1.23,115,112,093,0000,1",
"C1.23,115,112,093,0000,0",
"C1.23,116,112,093,0000,0",
"C1.23,116,112,093,0000,1",
"C1.23,117,112,093,0000,0",
"C1.23,117,112,093,0000,1",
"C1.23,120,124,092,0000,1",
"C1.23,120,124,092,0000,1",
"C1.23,121,124,091,0000,1",
"C1.23,121,124,091,0000,1",
"C1.23,122,124,091,0000,1",
"C1.23,123,124,091,0000,1",
"C1.23,124,124,091,0000,1",
"C1.23,124,124,091,0000,1",
"C1.23,125,124,091,0000,1",
"C1.23,125,124,090,0000,1",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,125,112,090,0000,1",
"C1.23,126,126,091,0000,0",
"C1.23,127,126,091,0000,0",
"C1.23,127,126,091,0000,0",
"C1.23,127,126,091,0000,0",
"C1.23,127,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,125,112,089,0000,1",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,127,126,089,0000,0",
"C1.23,127,126,089,0000,0",
"C1.23,127,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,125,112,088,0000,1",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,127,126,088,0000,0",
"C1.23,127,126,088,0000,0",
"C1.23,127,126,088,0000,0",
"C1.23,127,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,125,112,087,0000,1",
"C1.23,126,126,087,0000,0",
"C1.23,127,126,087,0000,0",
"C1.23,127,126,087,0000,0",
"C1.23,127,126,087,0000,0",
"C1.23,127,126,087,0000,0",
"C1.23,127,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,125,112,087,0000,1",
"C1.23,126,126,087,0000,0",
"C1.23,127,126,087,0000,0",
"C1.23,127,126,087,0000,0",
"C1.23,127,126,086,0000,0",
"C1.23,127,126,086,0000,0",
"C1.23,127,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,125,112,086,0000,1",
"C1.23,126,126,086,0000,0",
"C1.23,127,126,086,0000,0",
"C1.23,127,126,086,0000,0",
"C1.23,127,126,086,0000,0",
"C1.23,127,126,085,0000,0",
"C1.23,126,126,081,0000,0",
"C1.23,126,126,080,0000,0",
"C1.23,126,126,080,0000,0",
"C1.23,126,126,081,0000,0",
"C1.23,126,126,082,0000,0",
"C1.23,126,126,082,0000,0",
"C1.23,126,126,083,0000,0",
"C1.23,126,126,084,0000,0",
"C1.23,126,126,084,0000,0",
"C1.23,126,126,085,0000,0",
"C1.23,126,126,085,0000,0",
"C1.23,126,126,085,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,126,126,086,0000,0",
"C1.23,125,112,086,0000,1",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,087,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,088,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,125,112,089,0000,1",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,089,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,126,126,090,0000,0",
"C1.23,125,112,091,0000,1",
"C1.23,126,126,091,0000,0",
"C1.23,126,126,091,0000,0",
"C1.23,126,126,091,0000,0",
"C1.23,126,126,091,0000,0",
"C1.23,126,126,091,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,125,126,092,0000,0",
"C1.23,125,112,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,092,0000,0",
"C1.23,126,126,093,0000,0",
"C1.23,126,126,093,0000,0",
"C1.23,126,126,093,0000,0",
"C1.23,126,126,093,0000,0",
"C1.23,126,126,093,0000,0",
"C1.23,125,112,093,0000,1"
"C1.23,116,000,094,0000,0", //machines goes into standby
"C1.23,116,000,094,0000,0",
"C1.23,116,000,094,0000,0",
"C1.23,116,000,094,0000,0",
"C1.23,116,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,115,000,094,0000,0",
"C1.23,114,000,094,0000,0",
};

static int i = 0;

SoftwareSerial extSerial(D5, D6);

void setup() {
  Serial.begin(9600);
  extSerial.begin(9600);
}

void loop() {

  int x;

  //Send for 5 secs the same data
  for (x = 0; x < 10; x++ ) {
    Serial.println( output[i] );      
    extSerial.println(output[i]);
    delay(400);
  }     
  if (i == 687) {
    i = 0;
  } else {
    i++;
  }
  
}