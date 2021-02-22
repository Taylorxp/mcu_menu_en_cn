/***************************************************************************************************
* FILE: menu_content.c

* DESCRIPTION:  系统菜单内容定义

***************************************************************************************************/
#include "menu_framework.h"
#include "system.h"
#include "ccp.h"
#include "visca2camera.h"

/* 顶层菜单 */

/* 串口设置 */
void Set_Serial(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Protocol(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Address(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_BaudRate(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_SpeedGrade(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_SpeedLimit(int todo, MENU_LIST_ITEM_ST &this_item);

/* 云台设置 */
void Set_Ptz(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_DZoom(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_FocusMode(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_AfSens(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_RemoteSpeed(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_RemoteSpeedLimit(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_PresetSpeed(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_PanDir(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_TiltDir(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Flip(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Mirror(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_PresetFreeze(int todo, MENU_LIST_ITEM_ST &this_item);

/* 曝光 */
void Set_Exposure(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_ExposureMode(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_ExposureGain(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Shutter(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Iris(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Bright(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_ExposureComp(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_BacklightComp(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_HighlightComp(int todo, MENU_LIST_ITEM_ST &this_item);


/* 白平衡 */
void Set_Wb(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_WbMode(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Rgain(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Bgain(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_WbOnePushTrigger(int todo, MENU_LIST_ITEM_ST &this_item);

/* 图像设置 */
void Set_Picture(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_2DNr(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_3DNr(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Contrast(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Chroma(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Acutance(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Hue(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Gamma(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Wdr(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Defog(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_DeFlick(int todo, MENU_LIST_ITEM_ST &this_item);

/* 网络设置 */
void Set_Net(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Dhcp(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_IpAddr(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_NetMask(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Gateway(int todo, MENU_LIST_ITEM_ST &this_item);

/* 系统设置 */
void Set_SysSet(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_VideoFormat(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_HdmiOutColorSpace(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_HdmiMode(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_CallPreset1(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_Language(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_SwVersion(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_FactoryPattern(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_PresetSavePic(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_CmdDebug(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_FactoryReset(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_ResetSystem(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_ResetPicture(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_ResetNet(int todo, MENU_LIST_ITEM_ST &this_item);
void Set_ResetAll(int todo, MENU_LIST_ITEM_ST &this_item);


/***************************************************************************************************
* VARIABLES
***************************************************************************************************/
const uint8_t strOnOff[][4] =
{
    "OFF",
    "ON ",
    "关 ",
    "开 ",
    "關 ",
    "開 ",  
};

/***************************************************************************************************
* Description: 顶层菜单表头
***************************************************************************************************/
const LIST_ITEM_ST stMenuName_Main = 
{
    0,
    {
        "               MENU                 ",
        "               设置                 ",
        "               菜單                 ",
    },
};


/******* 串口设置 *******/
const LIST_ITEM_ST stMenuItem_GotoCom = 
{
    Set_Serial,
    {
        "  Communication>                    ",
        "  串口设置>                         ",
        "  串口設置>                         ",
    },
};

const LIST_ITEM_ST stMenuItem_Protocol = 
{
    Set_Protocol,
    {
        "  Protocol:                         ",
        "  协议:                             ",
        "  協議:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Address = 
{
    Set_Address,
    {
        "  Address:                          ",
        "  地址:                             ",
        "  地址:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_BaudRate = 
{
    Set_BaudRate,
    {
        "  Baud Rate:                        ",
        "  波特率:                           ",
        "  波特率:                           ",
    },
};
const LIST_ITEM_ST stMenuItem_SpeedGrade = 
{
    Set_SpeedGrade,
    {
        "  Speed Scale:                      ",
        "  速度等级:                         ",
        "  速度等级:                         ",
    },
};
const LIST_ITEM_ST stMenuItem_SpeedLimit = 
{
    Set_SpeedLimit,
    {
        "  Speed Limit:                      ",
        "  速度限制:                         ",
        "  速度限制:                         ",
    },
};

/******* 云台设置 *******/
const LIST_ITEM_ST stMenuItem_GotoPtz = 
{
    Set_Ptz,
    {
        "  PTZ Settings>                     ",
        "  云台设置>                         ",
        "  雲台設置>                         ",
    },
};
const LIST_ITEM_ST stMenuItem_DZoom = 
{
    Set_DZoom,
    {
        "  DZoom:                            ",
        "  数字变倍:                         ",
        "  數字變倍:                         ",
    },
};
const LIST_ITEM_ST stMenuItem_FocusMode = 
{
    Set_FocusMode,
    {
        "  Focus Mode:                       ",
        "  聚焦模式:                         ",
        "  聚焦模式:                         ",
    },
};
//const LIST_ITEM_ST stMenuItem_AfSens = 
//{
//    Set_AfSens,
//    {
//        "  Focus Sensitivity:                ",
//        "  聚焦灵敏度:                       ",
//        "  聚焦灵敏度:                       ",
//    },
//};
const LIST_ITEM_ST stMenuItem_RemoteSpeed = 
{
    Set_RemoteSpeed,
    {
        "  Remote Speed:                     ",
        "  遥控速度:                         ",
        "  遙控速度:                         ",
    },
};
//const LIST_ITEM_ST stMenuItem_RemoteSpeedLimit = 
//{
//    Set_RemoteSpeedLimit,
//    {
//        "  Speed Limit:                     ",
//        "  速度限制:                        ",
//        "  速度限制:                        ",
//    },
//};
const LIST_ITEM_ST stMenuItem_PresetSpeed = 
{
    Set_PresetSpeed,
    {
        "  Preset Speed:                     ",
        "  预置位速度:                       ",
        "  预置位速度:                       ",
    },
};
const LIST_ITEM_ST stMenuItem_PanDir = 
{
    Set_PanDir,
    {
        "  Pan Direction:                   ",
        "  Pan方向:                         ",
        "  Pan方向:                         ",
    },
};
const LIST_ITEM_ST stMenuItem_TiltDir = 
{
    Set_TiltDir,
    {
        "  Tilt Direction:                  ",
        "  Tilt方向:                        ",
        "  Tilt方向:                        ",
    },
};
const LIST_ITEM_ST stMenuItem_Flip = 
{
    Set_Flip,
    {
        "  Flip:                             ",
        "  翻转:                             ",
        "  翻转:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Mirror = 
{
    Set_Mirror,
    {
        "  Mirror:                           ",
        "  镜像:                             ",
        "  鏡像:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_PresetFreeze = 
{
    Set_PresetFreeze,
    {
        "  Preset Freeze:                    ",
        "  预置位冻结:                       ",
        "  预置位凍結:                       ",
    },
};

/******* 曝光 *******/
const LIST_ITEM_ST stMenuItem_Exposure = 
{
    Set_Exposure,
    {
        "  Exposure Settings>                ",
        "  曝光>                             ",
        "  曝光>                             ",
    },
};
const LIST_ITEM_ST stMenuItem_ExposureMode = 
{
    Set_ExposureMode,
    {
        "  Exposure Mode:                    ",
        "  曝光模式:                         ",
        "  曝光模式:                         ",
    },
};
const LIST_ITEM_ST stMenuItem_ExposureGain = 
{
    Set_ExposureGain,
    {
        "  Gain:                             ",
        "  增益:                             ",
        "  增益:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Iris = 
{
    Set_Iris,
    {
        "  Iris:                             ",
        "  光圈:                             ",
        "  光圈:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Shutter = 
{
    Set_Shutter,
    {
        "  Shutter:                          ",
        "  快门:                             ",
        "  快門:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Bright = 
{
    Set_Bright,
    {
        "  Bright:                           ",
        "  亮度:                             ",
        "  亮度:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_ExposureComp = 
{
    Set_ExposureComp,
    {
        "  Exp Compensation:                 ",
        "  曝光补偿:                         ",
        "  曝光补偿:                         ",
    },
};
const LIST_ITEM_ST stMenuItem_BacklightComp = 
{
    Set_BacklightComp,
    {
        "  Backlight:                        ",
        "  背光补偿:                         ",
        "  背光补偿:                         ",
    },
};
//const LIST_ITEM_ST stMenuItem_HighlightComp = 
//{
//    Set_HighlightComp,
//    {
//        "  Highlight:                        ",
//        "  高光抑制:                         ",
//        "  高光抑制:                         ",
//    },
//};

/******* 白平衡 *******/
const LIST_ITEM_ST stMenuItem_Wb = 
{
    Set_Wb,
    {
        "  WB Settings>                      ",
        "  白平衡>                           ",
        "  白平衡>                           ",
    },
};
const LIST_ITEM_ST stMenuItem_WbMode = 
{
    Set_WbMode,
    {
        "  Mode:                             ",
        "  模式:                             ",
        "  模式:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Rgain = 
{
    Set_Rgain,
    {
        "  RGAIN:                            ",
        "  RGAIN:                            ",
        "  RGAIN:                            ",
    },
};
const LIST_ITEM_ST stMenuItem_Bgain = 
{
    Set_Bgain,
    {
        "  BGAIN:                            ",
        "  BGAIN:                            ",
        "  BGAIN:                            ",
    },
};
const LIST_ITEM_ST stMenuItem_WbOnePushTrigger = 
{
    Set_WbOnePushTrigger,
    {
        "  Trigger:                          ",
        "  触发>                             ",
        "  触发>                             ",
    },
};

/******* 图像设置 *******/
const LIST_ITEM_ST stMenuItem_Picture = 
{
    Set_Picture,
    {
        "  Picture Settings>                 ",
        "  图像设置>                         ",
        "  圖像設置>                         ",
    },
};
const LIST_ITEM_ST stMenuItem_2DNr = 
{
    Set_2DNr,
    {
        "  2DNR:                             ",
        "  2D降噪:                           ",
        "  2D降噪:                           ",
    },
};
const LIST_ITEM_ST stMenuItem_3DNr = 
{
    Set_3DNr,
    {
        "  3DNR:                             ",
        "  3D降噪:                           ",
        "  3D降噪:                           ",
    },
};
const LIST_ITEM_ST stMenuItem_Contrast = 
{
    Set_Contrast,
    {
        "  Contrast:                         ",
        "  对比度:                           ",
        "  对比度:                           ",
    },
};
const LIST_ITEM_ST stMenuItem_Chroma = 
{
    Set_Chroma,
    {
        "  Chroma:                           ",
        "  色度:                             ",
        "  色度:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Acutance = 
{
    Set_Acutance,
    {
        "  Acutance:                         ",
        "  锐度:                             ",
        "  锐度:                             ",
    },
};
//const LIST_ITEM_ST stMenuItem_Hue = 
//{
//    Set_Hue,
//    {
//        "  HUE:                              ",
//        "  色调:                             ",
//        "  色调:                             ",
//    },
//};
const LIST_ITEM_ST stMenuItem_Gamma = 
{
    Set_Gamma,
    {
        "  Gamma:                            ",
        "  伽马:                             ",
        "  伽馬:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Defog = 
{
    Set_Defog,
    {
        "  Defog:                            ",
        "  去雾:                             ",
        "  去雾:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Wdr = 
{
    Set_Wdr,
    {
        "  WDR:                              ",
        "  宽动态:                           ",
        "  寬動態:                           ",
    },
};
const LIST_ITEM_ST stMenuItem_DeFlick = 
{
    Set_DeFlick,
    {
        "  Flick:                            ",
        "  抗闪烁:                           ",
        "  抗闪烁:                           ",
    },
};

/******* 网络设置 *******/
const LIST_ITEM_ST stMenuItem_Net = 
{
    Set_Net,
    {
        "  Net Infomation>                   ",
        "  网络设置>                         ",
        "  网络设置>                         ",
    },
};
const LIST_ITEM_ST stMenuItem_Dhcp = 
{
    Set_Dhcp,
    {
        "  DHCP:                             ",
        "  DHCP:                             ",
        "  DHCP:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_IpAddr =
{
    Set_IpAddr,
    {
        "  IP Address:                       ",
        "  IP地址:                           ",
        "  IP地址:                           ",
    },
};
const LIST_ITEM_ST stMenuItem_NetMask =
{
    Set_NetMask,
    {
        "  Mask:                             ",
        "  掩码:                             ",
        "  掩碼:                             ",
    },
};
const LIST_ITEM_ST stMenuItem_Gateway =
{
    Set_Gateway,
    {
        "  Gateway:                          ",
        "  网关:                             ",
        "  網關:                             ",
    },
};

/******* 系统设置 *******/
const LIST_ITEM_ST stMenuItem_SysSet = 
{
    Set_SysSet,
    {
        "  System Settings>                  ",
        "  系统设置>                         ",
        "  系统设置>                         ",
    },
};
const LIST_ITEM_ST stMenuItem_VideoFormat = 
{
    Set_VideoFormat,
    {
        "  Resolution:                       ",
        "  视频格式:                         ",
        "  視頻格式:                         ",
    },
};
const LIST_ITEM_ST stMenuItem_HdmiOutColorSpace = 
{
    Set_HdmiOutColorSpace,
    {
        "  HDMI Color:                       ",
        "  HDMI色彩空间:                     ",
        "  HDMI色彩空間:                     ",
    },
};
const LIST_ITEM_ST stMenuItem_HdmiMode = 
{
    Set_HdmiMode,
    {
        "  HDMI Mode:                        ",
        "  HDMI模式:                         ",
        "  HDMI模式:                         ",
    },
};
const LIST_ITEM_ST stMenuItem_CallPreset1 = 
{
    Set_CallPreset1,
    {
        "  Reload Preset 1:                  ",
        "  开机1号看守位:                    ",
        "  开机1号看守位:                    ",
    },
};

const LIST_ITEM_ST stMenuItem_Language = 
{
    Set_Language,
    {
        "  Language:                         ",
        "  语言:                             ",
        "  語言:                             ",
    },
};

const LIST_ITEM_ST stMenuItem_SwVersion = 
{
    Set_SwVersion,
    {
        "  Version:          " OSD_VERSION,
        "  软件版本:         " OSD_VERSION,
        "  軟體版本:         " OSD_VERSION,
    },
};

const LIST_ITEM_ST stMenuItem_Factory = 
{
    NULL,
    {
        "  Factory Pattern>                  ",
        "  工厂模式>                         ",
        "  工厂模式>                         ",
    },
};

const LIST_ITEM_ST stMenuItem_FactoryPattern = 
{
    Set_FactoryPattern,
    {
        "  Factory Pattern:                  ",
        "  工厂模式:                         ",
        "  工厂模式:                         ",
    },
};

const LIST_ITEM_ST stMenuItem_PresetSavePic = 
{
    Set_PresetSavePic,
    {
        "  Preset Picture:                   ",
        "  Preset Picture:                   ",
        "  Preset Picture:                   ",
    },
};

//const LIST_ITEM_ST stMenuItem_CmdDebug = 
//{
//    Set_CmdDebug,
//    {
//        "                                    ",
//        "                                    ",
//        "                                    ",
//    },
//};

const LIST_ITEM_ST stMenuItem_FactoryReset = 
{
    Set_FactoryReset,
    {
        "  Factory Reset>                    ",
        "  恢复出厂设置>                     ",
        "  恢復出廠設置>                     ",
    },
};
const LIST_ITEM_ST stMenuItem_ResetSystem = 
{
    Set_ResetSystem,
    {
        "  Reset System>                     ",
        "  恢复系统>                         ",
        "  恢复系统>                         ",
    },
};
const LIST_ITEM_ST stMenuItem_ResetPicture = 
{
    Set_ResetPicture,
    {
        "  Reset Picture>                    ",
        "  恢复图像>                         ",
        "  恢复图像>                         ",
    },
};
const LIST_ITEM_ST stMenuItem_ResetNet = 
{
    Set_ResetNet,
    {
        "  Reset Net>                        ",
        "  恢复网络>                         ",
        "  恢复网络>                         ",
    },
};
const LIST_ITEM_ST stMenuItem_ResetAll = 
{
    Set_ResetAll,
    {
        "  Reset All>                        ",
        "  恢复全部>                         ",
        "  恢复全部>                         ",
    },
};


/***************************************************************************************************
* Description:  数字转字符串
***************************************************************************************************/
uint8_t* NumToString(uint16_t num)
{
    static uint8_t buffer[3] = {0};
    if(num < 10)
    {
        buffer[0] = num + '0';
        buffer[1] = ' ';
        buffer[2] = ' ';
    }
    else if(num < 100)
    {
        buffer[0] = num / 10 + '0';
        buffer[1] = num % 10 + '0';
        buffer[2] = ' ';
    }
    else
    {
        buffer[0] = num / 100 + '0';
        buffer[1] = num % 100 / 10+ '0';
        buffer[2] = num % 100 % 10+ '0';
    }
    return buffer;
}

//uint8_t NumToString2(uint16_t num)
//{
//    static uint8_t str_buffer[5] = {0};
//    uint8_t count = 0;
//    uint8_t index = 4;
//    uint8_t temp;
//    
//    do{
//        temp = num % 10;
//        str_buffer[index--] = temp + '0';
//        num /= 10;
//        count++;
//    }while(num != 0);
//    return count;
//}
char *NumToString3(uint8_t num)
{
    static char str_buffer[] = "000";
    str_buffer[0] = num / 100 + '0';
    str_buffer[1] = num % 100 / 10 + '0';
    str_buffer[2] = num % 100 % 10 + '0';
    return str_buffer;
}

/***************************************************************************************************
* Description:  IP地址转字符串
***************************************************************************************************/
uint8_t* IpAddrToStr(uint32_t val)
{
    static uint8_t net[16] = "123.123.123.123";
    uint8_t temp;
    
    temp = (uint8_t)((val>>24)&0xFF);
    memcpy(&net[0], NumToString3(temp), 3);
    net[3] = '.';
    
    temp = (uint8_t)((val>>16)&0xFF);
    memcpy(&net[4], NumToString3(temp), 3);
    net[7] = '.';
    
    temp = (uint8_t)((val>>8)&0xFF);
    memcpy(&net[8], NumToString3(temp), 3);
    net[11] = '.';
    
    temp = (uint8_t)((val>>0)&0xFF);
    memcpy(&net[12], NumToString3(temp), 3);
    
    return net;
}

/***************************************************************************************************
* Description: 串口设置
***************************************************************************************************/
void Set_Serial(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        break;
        case MENU_LEFT:
        break;
        case MENU_RIGHT:
        case MENU_ENTER:
        Menu->CreateList(stMenuItem_GotoCom);
        Menu->ListApendItem(stMenuItem_Protocol);
        Menu->ListApendItem(stMenuItem_Address);
        Menu->ListApendItem(stMenuItem_BaudRate);
        Menu->ListApendItem(stMenuItem_SpeedGrade);
        Menu->ListApendItem(stMenuItem_SpeedLimit);
        
        Menu->Show();
        break;
    }
}
void Set_Protocol(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strProtocol[][8] =
    {
        "AUTO   ",
        "VISCA  ",
        "PELCO D",
        "PELCO P",
        "自动   ",
        "VISCA  ",
        "PELCO D",
        "PELCO P",
        "自動   ",
        "VISCA  ",
        "PELCO D",
        "PELCO P",
    };
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(CUR_PTC_TYPE > CCP_AUTO) CUR_PTC_TYPE--;
        else CUR_PTC_TYPE = CCP_PELCO_P;
        break;
        case MENU_RIGHT:
        if(CUR_PTC_TYPE < CCP_PELCO_P) CUR_PTC_TYPE++;
        else CUR_PTC_TYPE = CCP_AUTO;
        break;
    }
    if((CUR_PTC_TYPE == CCP_AUTO) || (CUR_PTC_TYPE == CCP_VISCA))
    {
        if(CUR_PTC_ADDR > 7) CUR_PTC_ADDR = 1;
    }
    index = CUR_PTC_TYPE;
    index += Menu->getLanguageIndex() * 4;
    memcpy(&this_item.text[20], strProtocol[index], 7);
}
void Set_Address(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if((CUR_PTC_TYPE == CCP_AUTO) || (CUR_PTC_TYPE == CCP_VISCA))
        {
            if(CUR_PTC_ADDR > 1) CUR_PTC_ADDR--;
            else CUR_PTC_ADDR = 7;
        }
        else if(CUR_PTC_TYPE == CCP_PELCO_D || CUR_PTC_TYPE == CCP_PELCO_P)
        {
            if(CUR_PTC_ADDR > 0) CUR_PTC_ADDR--;
            else CUR_PTC_ADDR = 255;
        }
        break;
        case MENU_RIGHT:
        if((CUR_PTC_TYPE == CCP_AUTO) || (CUR_PTC_TYPE == CCP_VISCA))
        {
            if(CUR_PTC_ADDR < 7) CUR_PTC_ADDR++;
            else CUR_PTC_ADDR = 1;
        }
        else if(CUR_PTC_TYPE == CCP_PELCO_D || CUR_PTC_TYPE == CCP_PELCO_P)
        {
            if(CUR_PTC_ADDR < 255) CUR_PTC_ADDR++;
            else CUR_PTC_ADDR = 0;
        }
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(CUR_PTC_ADDR), 3);
}
void Set_BaudRate(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strBaudRate[6][7] =
    {
        "2400  ",
        "4800  ",
        "9600  ",
        "19200 ",
        "38400 ",
        "115200",
    };
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(PTC_BAUDRATE > BAUD_2400) PTC_BAUDRATE--;
        else PTC_BAUDRATE = BAUD_115200;
        break;
        case MENU_RIGHT:
        if(PTC_BAUDRATE < BAUD_115200) PTC_BAUDRATE++;
        else PTC_BAUDRATE = BAUD_2400;
        break;
    }
    memcpy(&(this_item.text[20]), strBaudRate[PTC_BAUDRATE], 6);
}
void Set_SpeedGrade(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strSpeedGrade[][5] =
    {
        "STD ",
        "EXP ",
        "标准",
        "扩展",
        "標準",
        "擴展",
    };
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(CUR_SPEED_GRADE != 0) CUR_SPEED_GRADE = 0;
        else CUR_SPEED_GRADE = 1;
        break;
    }
    uint8_t index = CUR_SPEED_GRADE;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strSpeedGrade[index], 4);
}
void Set_SpeedLimit(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(PTC_SPEED_LIMIT != ON) PTC_SPEED_LIMIT = ON;
        else PTC_SPEED_LIMIT = OFF;
        break;
    }
    index = PTC_SPEED_LIMIT;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}

/***************************************************************************************************
* Description: 云台设置
***************************************************************************************************/
void Set_Ptz(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        break;
        case MENU_LEFT:
        break;
        case MENU_RIGHT:
        case MENU_ENTER:
        Menu->CreateList(stMenuItem_GotoPtz);
        Menu->ListApendItem(stMenuItem_DZoom);
        Menu->ListApendItem(stMenuItem_FocusMode);
        //        Menu->ListApendItem(stMenuItem_AfSens);
        Menu->ListApendItem(stMenuItem_RemoteSpeed);
        //        Menu->ListApendItem(stMenuItem_RemoteSpeedLimit);
		Menu->ListApendItem(stMenuItem_PresetSpeed);
        Menu->ListApendItem(stMenuItem_PanDir);
        Menu->ListApendItem(stMenuItem_TiltDir);
        Menu->ListApendItem(stMenuItem_Flip);
        Menu->ListApendItem(stMenuItem_Mirror);
		Menu->ListApendItem(stMenuItem_PresetFreeze);
        Menu->Show();
        break;
    }
}
void Set_DZoom(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.dzoom == VISCA_OFF)
            stCamInfo.dzoom = VISCA_ON;
        else
            stCamInfo.dzoom = VISCA_OFF;
        visca_set_8bits_value(VISCA_DZOOM, stCamInfo.dzoom, 0);
        break;
    }
    
    index = stCamInfo.dzoom == VISCA_ON ? 1:0;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}
void Set_FocusMode(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strFocusMode[][13] =
    {    
        "AUTO        ",
        "MANUAL      ",
        "Zoom Trigger",
        "自动        ",
        "手动        ",
        "键控        ",
        "自動        ",
        "手動        ",
        "鍵控        ",
    };
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.focus_mode == VISCA_FOCUS_AUTO) stCamInfo.focus_mode = VISCA_FOCUS_MANUAL;
        else stCamInfo.focus_mode = VISCA_FOCUS_AUTO;
        visca_set_8bits_value(VISCA_FOCUS_MODE, stCamInfo.focus_mode, 0);
        break;
    }
    
    index = stCamInfo.focus_mode == VISCA_FOCUS_AUTO ? 0:1;
    index += Menu->getLanguageIndex() * 3;
    memcpy(&this_item.text[20], strFocusMode[index], 12);
}
void Set_AfSens(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strAfSens[][7] = 
    {
        "Normal",
        "Low   ",
        "正常  ",
        "低    ",
        "正常  ",
        "低    ",
    };
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.af_sens == VISCA_AFS_NORMAL) stCamInfo.af_sens = VISCA_AFS_LOW;
        else stCamInfo.af_sens = VISCA_AFS_NORMAL;
        cam_af_sens(stCamInfo.af_sens);
        break;
    }
    
    uint8_t index = stCamInfo.af_sens == VISCA_AFS_NORMAL ? 0:1;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strAfSens[index], 6);
}
void Set_RemoteSpeed(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stSysInfo.remote_speed > 1) stSysInfo.remote_speed--;
        else stSysInfo.remote_speed = 16;
        break;
        case MENU_RIGHT:
        if(stSysInfo.remote_speed < 16) stSysInfo.remote_speed++;
        else stSysInfo.remote_speed = 1;
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stSysInfo.remote_speed), 3);
}
void Set_RemoteSpeedLimit(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stSysInfo.remote_speedlimit != ON) stSysInfo.remote_speedlimit = ON;
        else stSysInfo.remote_speedlimit = OFF;
        break;
    }
    index = stSysInfo.remote_speedlimit;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}
void Set_PresetSpeed(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stSysInfo.preset_speed > 10) stSysInfo.preset_speed--;
        else stSysInfo.preset_speed = 60;
        break;
        case MENU_RIGHT:
        if(stSysInfo.preset_speed < 60) stSysInfo.preset_speed++;
        else stSysInfo.preset_speed = 10;
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stSysInfo.preset_speed), 3);
}
const uint8_t strPtDir[][10] =
{
    "Normal   ",
    "Inversion",
    "正常     ",
    "反向     ",
    "正常     ",
    "反向     ",
};
void Set_PanDir(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stSysInfo.pan_inversion != ON) stSysInfo.pan_inversion = ON;
        else stSysInfo.pan_inversion = OFF;
        break;
    }
    index = stSysInfo.pan_inversion;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strPtDir[index], 9);
}
void Set_TiltDir(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stSysInfo.tilt_inversion != ON) stSysInfo.tilt_inversion = ON;
        else stSysInfo.tilt_inversion = OFF;
        break;
    }
    index = stSysInfo.tilt_inversion;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strPtDir[index], 9);
}
void Set_Flip(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.flip == VISCA_ON) stCamInfo.flip = VISCA_OFF;
        else stCamInfo.flip = VISCA_ON;
        cam_flip(stCamInfo.flip);
        break;
    }
    index = stCamInfo.flip == VISCA_ON ? 1:0;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}
void Set_Mirror(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.mirror == VISCA_ON) stCamInfo.mirror = VISCA_OFF;
        else stCamInfo.mirror = VISCA_ON;
        cam_mirror(stCamInfo.mirror);
        break;
    }
    index = stCamInfo.mirror == VISCA_ON ? 1:0;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}
void Set_PresetFreeze(int todo, MENU_LIST_ITEM_ST &this_item)
{
	uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stSysInfo.preset_freeze == ON) stSysInfo.preset_freeze = OFF;
        else stSysInfo.preset_freeze = ON;
        break;
    }
    index = stSysInfo.preset_freeze;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}

/***************************************************************************************************
* Description:  曝光
***************************************************************************************************/
void Set_Exposure(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        break;
        case MENU_LEFT:
        break;
        case MENU_RIGHT:
        case MENU_ENTER:
        Menu->CreateList(stMenuItem_Exposure);
        Menu->ListApendItem(stMenuItem_ExposureMode);
        if(stCamInfo.exp_mode == VISCA_EXP_MANUAL)
        {
            Menu->ListApendItem(stMenuItem_ExposureGain);
            Menu->ListApendItem(stMenuItem_Shutter);
            Menu->ListApendItem(stMenuItem_Iris);
        }
        else if(stCamInfo.exp_mode == VISCA_EXP_SHUTTER_PRIORITY)
        {
            Menu->ListApendItem(stMenuItem_Shutter);
            Menu->ListApendItem(stMenuItem_ExposureComp);
            Menu->ListApendItem(stMenuItem_BacklightComp);
            //            Menu->ListApendItem(stMenuItem_HighlightComp);
        }
        else if(stCamInfo.exp_mode == VISCA_EXP_IRIS_PRIORITY)
        {
            Menu->ListApendItem(stMenuItem_Iris);
            Menu->ListApendItem(stMenuItem_ExposureComp);
            Menu->ListApendItem(stMenuItem_BacklightComp);
            //            Menu->ListApendItem(stMenuItem_HighlightComp);
        }
        else if(stCamInfo.exp_mode == VISCA_EXP_BRIGHT_PRIORITY)
        {
            Menu->ListApendItem(stMenuItem_Bright);
        }
        else
        {
            Menu->ListApendItem(stMenuItem_ExposureComp);
            Menu->ListApendItem(stMenuItem_BacklightComp);
            //            Menu->ListApendItem(stMenuItem_HighlightComp);
        }
        
        Menu->Show();
        break;
    }
}
uint8_t TransAeMode()
{
    uint8_t ret;
    switch(stCamInfo.exp_mode)
    {
        case VISCA_EXP_FULL_AUTO:        ret = 0; break;
        case VISCA_EXP_MANUAL:           ret = 1; break;
        case VISCA_EXP_SHUTTER_PRIORITY: ret = 2; break;
        case VISCA_EXP_IRIS_PRIORITY:    ret = 3; break;
        case VISCA_EXP_BRIGHT_PRIORITY:  ret = 4; break;
        default: ret = 0; break;
    }
    return ret;
}
void Set_ExposureMode(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strAeMode[][12] = 
    {
        "Full Auto  ",
        "Manual     ",
        "Shutter Pri",
        "Iris Pri   ",
        "Bright Pri ",
        "自动       ",
        "手动       ",
        "快门优先   ",
        "光圈优先   ",
        "亮度优先   ",
        "自動       ",
        "手動       ",
        "快門優先   ",
        "光圈優先   ",
        "亮度優先   ",
    };
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        index = TransAeMode();
        index += Menu->getLanguageIndex() * 5;
        memcpy(&this_item.text[20], strAeMode[index], 11);
        return;
        break;
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.exp_mode == VISCA_EXP_FULL_AUTO) stCamInfo.exp_mode = VISCA_EXP_MANUAL;
        else if(stCamInfo.exp_mode == VISCA_EXP_MANUAL) stCamInfo.exp_mode = VISCA_EXP_BRIGHT_PRIORITY;
        else if(stCamInfo.exp_mode == VISCA_EXP_BRIGHT_PRIORITY) stCamInfo.exp_mode = VISCA_EXP_IRIS_PRIORITY;
        else if(stCamInfo.exp_mode == VISCA_EXP_IRIS_PRIORITY) stCamInfo.exp_mode = VISCA_EXP_SHUTTER_PRIORITY;
        else stCamInfo.exp_mode = VISCA_EXP_FULL_AUTO;
        cam_exp_mode(stCamInfo.exp_mode);
        Menu->BackNoRefresh();
        Menu->Enter();
        break;
        case MENU_RIGHT:
        if(stCamInfo.exp_mode == VISCA_EXP_FULL_AUTO) stCamInfo.exp_mode = VISCA_EXP_SHUTTER_PRIORITY;
        else if(stCamInfo.exp_mode == VISCA_EXP_SHUTTER_PRIORITY) stCamInfo.exp_mode = VISCA_EXP_IRIS_PRIORITY;
        else if(stCamInfo.exp_mode == VISCA_EXP_IRIS_PRIORITY) stCamInfo.exp_mode = VISCA_EXP_BRIGHT_PRIORITY;
        else if(stCamInfo.exp_mode == VISCA_EXP_BRIGHT_PRIORITY) stCamInfo.exp_mode = VISCA_EXP_MANUAL;
        else stCamInfo.exp_mode = VISCA_EXP_FULL_AUTO;
        cam_exp_mode(stCamInfo.exp_mode);
        Menu->BackNoRefresh();
        Menu->Enter();
        break;
    }
}
void Set_Shutter(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strShutterSpeed25[][7] = 
    {
        "1/1   ", "1/2   ", "1/3   ", "1/6   ",
        "1/12  ", "1/25  ", "1/50  ", "1/75  ",
        "1/100 ", "1/120 ", "1/150 ", "1/215 ",
        "1/300 ", "1/425 ", "1/600 ", "1/1000",
        "1/1250", "1/1750", "1/2500", "1/3500",
        "1/6000", "1/10K ",
    };
    const uint8_t strShutterSpeed30[][7] = 
    {
        "1/1   ", "1/2   ", "1/4   ", "1/8   ",
        "1/15  ", "1/30  ", "1/60  ", "1/90  ",
        "1/100 ", "1/125 ", "1/180 ", "1/250 ",
        "1/350 ", "1/500 ", "1/725 ", "1/1000",
        "1/1500", "1/2000", "1/3000", "1/4000",
        "1/6000", "1/10K ",
    };
    
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.exp_mode != VISCA_EXP_SHUTTER_PRIORITY && stCamInfo.exp_mode != VISCA_EXP_MANUAL) return;
        if(stCamInfo.exp_shutter > MIN_SHUTTER) stCamInfo.exp_shutter--;
        else stCamInfo.exp_shutter = MAX_SHUTTER;
        visca_set_16bits_value(VISCA_EXP_SHUTTER_DIRECT, stCamInfo.exp_shutter, 0);
        break;
        case MENU_RIGHT:
        if(stCamInfo.exp_mode != VISCA_EXP_SHUTTER_PRIORITY && stCamInfo.exp_mode != VISCA_EXP_MANUAL) return;
        if(stCamInfo.exp_shutter < MAX_SHUTTER) stCamInfo.exp_shutter++;
        else stCamInfo.exp_shutter = MIN_SHUTTER;
        visca_set_16bits_value(VISCA_EXP_SHUTTER_DIRECT, stCamInfo.exp_shutter, 0);
        break;
    }
    if(stSysInfo.video_format_out1 == VIDEO_1920x1080p25)
        memcpy(&this_item.text[20], strShutterSpeed25[stCamInfo.exp_shutter], 6);
    else
        memcpy(&this_item.text[20], strShutterSpeed30[stCamInfo.exp_shutter], 6); 
}
void Set_Iris(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strIris[][6] = {
        "Close", "F14  ", "F11  ", "F9.6 ",
        "F8   ", "F6.8 ", "F5.6 ", "F4.8 ",
        "F4   ", "F3.4 ", "F2.8 ", "F2.4 ",
        "F2   ", "F1.8 ",
    };
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.exp_mode != VISCA_EXP_IRIS_PRIORITY && stCamInfo.exp_mode != VISCA_EXP_MANUAL) return;
        if(stCamInfo.exp_iris > MIN_IRIS) stCamInfo.exp_iris--;
        else stCamInfo.exp_iris = MAX_IRIS;
        visca_set_16bits_value(VISCA_EXP_IRIS_DIRECT, stCamInfo.exp_iris, 0);
        break;
        case MENU_RIGHT:
        if(stCamInfo.exp_mode != VISCA_EXP_IRIS_PRIORITY && stCamInfo.exp_mode != VISCA_EXP_MANUAL) return;
        if(stCamInfo.exp_iris < MAX_IRIS) stCamInfo.exp_iris++;
        else stCamInfo.exp_iris = MIN_IRIS;
        visca_set_16bits_value(VISCA_EXP_IRIS_DIRECT, stCamInfo.exp_iris, 0);
        break;
    }
    memcpy(&(this_item.text[20]), strIris[stCamInfo.exp_iris], 5);
}
void Set_ExposureGain(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.exp_mode != VISCA_EXP_MANUAL) return;
        if(stCamInfo.exp_gain > MIN_GAIN) stCamInfo.exp_gain--;
        else stCamInfo.exp_gain = MAX_GAIN;
        visca_set_16bits_value(VISCA_EXP_GAIN_DIRECT, stCamInfo.exp_gain, 0);
        break;
        case MENU_RIGHT:
        if(stCamInfo.exp_mode != VISCA_EXP_MANUAL) return;
        if(stCamInfo.exp_gain < MAX_GAIN) stCamInfo.exp_gain++;
        else stCamInfo.exp_gain = MIN_GAIN;
        visca_set_16bits_value(VISCA_EXP_GAIN_DIRECT, stCamInfo.exp_gain, 0);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.exp_gain+1), 3);
}
void Set_Bright(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.exp_mode != VISCA_EXP_BRIGHT_PRIORITY) return;
        if(stCamInfo.exp_bright > MIN_BRIGHT) stCamInfo.exp_bright--;
        else stCamInfo.exp_bright = MAX_BRIGHT;
        visca_set_16bits_value(VISCA_EXP_BRIGHT_DIRECT, stCamInfo.exp_bright, 0);
        break;
        case MENU_RIGHT:
        if(stCamInfo.exp_mode != VISCA_EXP_BRIGHT_PRIORITY) return;
        if(stCamInfo.exp_bright < MAX_BRIGHT) stCamInfo.exp_bright++;
        else stCamInfo.exp_bright = MIN_BRIGHT;
        visca_set_16bits_value(VISCA_EXP_BRIGHT_DIRECT, stCamInfo.exp_bright, 0);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.exp_bright), 3);
}
void Set_ExposureComp(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.exp_comp > MIN_EXP_COMP) stCamInfo.exp_comp--;
        else stCamInfo.exp_comp = MAX_EXP_COMP;
        visca_set_16bits_value(YHW_NEWBRIGHT, stCamInfo.exp_comp, 0);
        //        visca_set_8bits_value(VISCA_EXPCOMP_ONOFF, VISCA_EXPCOMP_ON, 0);
        //        visca_set_16bits_value(VISCA_EXPCOMP_DIRECT, stCamInfo.exp_comp, 0);
        break;
        case MENU_RIGHT:
        if(stCamInfo.exp_comp < MAX_EXP_COMP) stCamInfo.exp_comp++;
        else stCamInfo.exp_comp = MIN_EXP_COMP;
        //        visca_set_8bits_value(VISCA_EXPCOMP_ONOFF, VISCA_EXPCOMP_ON, 0);
        //        visca_set_16bits_value(VISCA_EXPCOMP_DIRECT, stCamInfo.exp_comp, 0);
        visca_set_16bits_value(YHW_NEWBRIGHT, stCamInfo.exp_comp, 0);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.exp_comp), 3);
}
void Set_BacklightComp(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.backlight != VISCA_ON) stCamInfo.backlight = VISCA_ON;
        else stCamInfo.backlight = VISCA_OFF;
        cam_backlight(stCamInfo.backlight);
        break;
    }
    index = stCamInfo.backlight == VISCA_ON ? 1:0;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}
void Set_HighlightComp(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.highlight != VISCA_ON) stCamInfo.highlight = VISCA_ON;
        else stCamInfo.highlight = VISCA_OFF;
        cam_highlight(stCamInfo.highlight);
        break;
    }
    index = stCamInfo.highlight == VISCA_ON ? 1:0;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}

/***************************************************************************************************
* Description:  白平衡
***************************************************************************************************/
void Set_Wb(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        break;
        case MENU_LEFT:
        break;
        case MENU_RIGHT:
        case MENU_ENTER:
        Menu->CreateList(stMenuItem_Wb);
        Menu->ListApendItem(stMenuItem_WbMode);
        if(stCamInfo.wb_mode == VISCA_WB_MANUAL)
        {
            Menu->ListApendItem(stMenuItem_Rgain);
            Menu->ListApendItem(stMenuItem_Bgain);
        }
        else if(stCamInfo.wb_mode == VISCA_WB_ONE_PUSH_WB)
        {
            Menu->ListApendItem(stMenuItem_WbOnePushTrigger);
        }
        Menu->Show();
        break;
    }
}
void Set_WbMode(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strAwbMode[][9] = 
    {
        "Auto    ",
        "Indoor  ",
        "Outdoor ",
        "One Push",
        "ATW     ",
        "Manual  ",
        "自动    ",
        "室内    ",
        "室外    ",
        "键控    ",
        "ATW     ",
        "手动    ",
        "自動    ",
        "室内    ",
        "室外    ",
        "鍵控    ",
        "ATW     ",
        "手動    ",
    };
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        index = stCamInfo.wb_mode;
        index += Menu->getLanguageIndex() * 6;
        memcpy(&this_item.text[20], strAwbMode[index], 8);
        return;
        break;
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.wb_mode > VISCA_WB_AUTO) stCamInfo.wb_mode--;
        else stCamInfo.wb_mode = VISCA_WB_MANUAL;
        visca_set_8bits_value(VISCA_WB, stCamInfo.wb_mode, 0);
        Menu->BackNoRefresh();
        Menu->Enter();
        break;
        case MENU_RIGHT:
        if(stCamInfo.wb_mode < VISCA_WB_MANUAL) stCamInfo.wb_mode++;
        else stCamInfo.wb_mode = VISCA_WB_AUTO;
        visca_set_8bits_value(VISCA_WB, stCamInfo.wb_mode, 0);
        Menu->BackNoRefresh();
        Menu->Enter();
        break;
    }
}
void Set_Rgain(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.wb_mode != VISCA_WB_MANUAL) return;
        cam_rgain(VISCA_DOWN);
        break;
        case MENU_RIGHT:
        if(stCamInfo.wb_mode != VISCA_WB_MANUAL) return;
        cam_rgain(VISCA_UP);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.rgain), 3);
}
void Set_Bgain(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.wb_mode != VISCA_WB_MANUAL) return;
        cam_bgain(VISCA_DOWN);
        break;
        case MENU_RIGHT:
        if(stCamInfo.wb_mode != VISCA_WB_MANUAL) return;
        cam_bgain(VISCA_UP);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.bgain), 3);
}
void Set_WbOnePushTrigger(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        
        break;
        case MENU_LEFT:
        break;
        
        case MENU_ENTER:
        case MENU_RIGHT:
        cam_wb_onepush_trigger();
        break;
    }
}

/***************************************************************************************************
* Description: 进入图像设置子菜单
***************************************************************************************************/
void Set_Picture(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        break;
        case MENU_LEFT:
        break;
        case MENU_RIGHT:
        case MENU_ENTER:
        Menu->CreateList(stMenuItem_Picture);
        Menu->ListApendItem(stMenuItem_2DNr);
        Menu->ListApendItem(stMenuItem_3DNr);
        Menu->ListApendItem(stMenuItem_Contrast);
        Menu->ListApendItem(stMenuItem_Chroma);
        Menu->ListApendItem(stMenuItem_Acutance);
        //        Menu->ListApendItem(stMenuItem_Hue);
        Menu->ListApendItem(stMenuItem_Gamma);
        Menu->ListApendItem(stMenuItem_Wdr);
        Menu->ListApendItem(stMenuItem_Defog);
        Menu->ListApendItem(stMenuItem_DeFlick);
        
        Menu->Show();
        break;
    }
}
void Set_2DNr(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.nr2d == VISCA_ON) stCamInfo.nr2d = VISCA_OFF;
        else stCamInfo.nr2d = VISCA_ON;
        cam_2dnr(stCamInfo.nr2d);
        break;
    }
    index = stCamInfo.nr2d == VISCA_ON ? 1:0;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}
void Set_3DNr(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strNR[][7] = 
    {
        "OFF   ",
        "1     ",
        "2     ",
        "3     ",
        "4     ",
        "5     ",
        "关    ",
        "1     ",
        "2     ",
        "3     ",
        "4     ",
        "5     ",
        "關    ",
        "1     ",
        "2     ",
        "3     ",
        "4     ",
        "5     ",
    };
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.nr3d > MIN_NR) stCamInfo.nr3d--;
        else stCamInfo.nr3d = MAX_NR;
        cam_3dnr(stCamInfo.nr3d);
        break;
        case MENU_RIGHT:
        if(stCamInfo.nr3d < MAX_NR) stCamInfo.nr3d++;
        else stCamInfo.nr3d = MIN_NR;
        cam_3dnr(stCamInfo.nr3d);
        break;
    }
    index = stCamInfo.nr3d;
    index += Menu->getLanguageIndex() * 6;
    memcpy(&this_item.text[20], strNR[index], 6);
}
void Set_Contrast(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.contrast> MIN_CONTRAST) stCamInfo.contrast--;
        else stCamInfo.contrast = MAX_CONTRAST;
        cam_contrast_direct(stCamInfo.contrast);
        break;
        case MENU_RIGHT:
        if(stCamInfo.contrast < MAX_CONTRAST) stCamInfo.contrast++;
        else stCamInfo.contrast = MIN_CONTRAST;
        cam_contrast_direct(stCamInfo.contrast);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.contrast), 3);
}
void Set_Chroma(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.saturation > MIN_SATURATION) stCamInfo.saturation--;
        else stCamInfo.saturation = MAX_SATURATION;
        cam_saturation(stCamInfo.saturation);
        break;
        case MENU_RIGHT:
        if(stCamInfo.saturation < MAX_SATURATION) stCamInfo.saturation++;
        else stCamInfo.saturation = MIN_SATURATION;
        cam_saturation(stCamInfo.saturation);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.saturation), 3);
}
void Set_Acutance(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        cam_sharpness(VISCA_DOWN);
        break;
        case MENU_RIGHT:
        cam_sharpness(VISCA_UP);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.sharpness), 3);
}
void Set_Hue(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        
        break;
        case MENU_RIGHT:
        
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.hue), 3);
}
void Set_Gamma(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.gamma > MIN_GAMMA) stCamInfo.gamma--;
        else stCamInfo.gamma = MAX_GAMMA;
        cam_gamma(stCamInfo.gamma);
        break;
        case MENU_RIGHT:
        if(stCamInfo.gamma < MAX_GAMMA) stCamInfo.gamma++;
        else stCamInfo.gamma = MIN_GAMMA;
        cam_gamma(stCamInfo.gamma);
        break;
    }
    memcpy(&(this_item.text[20]), NumToString(stCamInfo.gamma), 3);
}
void Set_Wdr(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.wdr == VISCA_ON)
        {
            if(stCamInfo.wdr_level > MIN_WDR)
            {
                stCamInfo.wdr_level--;
                cam_wdr(stCamInfo.wdr_level);
            }
            else
            {
                stCamInfo.wdr = VISCA_OFF;
                cam_wdr(0);
            }
        }
        else
        {
            stCamInfo.wdr = VISCA_ON;
            stCamInfo.wdr_level = MAX_WDR;
            cam_wdr(stCamInfo.wdr_level);
        }
        break;
        case MENU_RIGHT:
        if(stCamInfo.wdr == VISCA_ON)
        {
            if(stCamInfo.wdr_level < MAX_WDR)
            {
                stCamInfo.wdr_level++;
                cam_wdr(stCamInfo.wdr_level);
            }
            else
            {
                stCamInfo.wdr = VISCA_OFF;
                cam_wdr(0);
            }
        }
        else
        {
            stCamInfo.wdr = VISCA_ON;
            stCamInfo.wdr_level = MIN_WDR;
            cam_wdr(stCamInfo.wdr_level);
        }
        break;
    }
    if(stCamInfo.wdr != VISCA_ON)
    {
        index = 0;
        index += Menu->getLanguageIndex() * 2;
        memcpy(&this_item.text[20], strOnOff[index], 3);
    }
    else
    {
        memcpy(&(this_item.text[20]), NumToString(stCamInfo.wdr_level), 3);
    }
}
void Set_Defog(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.defog > MIN_DEFOG) stCamInfo.defog--;
        else stCamInfo.defog = MAX_DEFOG;
        cam_defog(VISCA_ON, stCamInfo.defog);
        break;
        case MENU_RIGHT:
        if(stCamInfo.defog < MAX_DEFOG) stCamInfo.defog++;
        else stCamInfo.defog = MIN_DEFOG;
        cam_defog(VISCA_ON, stCamInfo.defog);
        break;
    }
    if(stCamInfo.defog == 0)
    {
        index = 0;
        index += Menu->getLanguageIndex() * 2;
        memcpy(&this_item.text[20], strOnOff[index], 3);
    }
    else
    {
        memcpy(&(this_item.text[20]), NumToString(stCamInfo.defog), 3);
    }
}
void Set_DeFlick(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strFlick[][5] = 
    {
        "OFF ",
        "50Hz",
        "60Hz",
        "关  ",
        "50Hz",
        "60Hz",
        "關  ",
        "50Hz",
        "60Hz",
    };
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        if(stCamInfo.flick > 0) stCamInfo.flick--;
        else stCamInfo.flick = 2;
        cam_flick(stCamInfo.flick);
        break;
        case MENU_RIGHT:
        if(stCamInfo.flick < 2) stCamInfo.flick++;
        else stCamInfo.flick = 0;
        cam_flick(stCamInfo.flick);
        break;
    }
    
    index = stCamInfo.flick;
    index += Menu->getLanguageIndex() * 3;
    memcpy(&this_item.text[20], strFlick[index], 4);
}

/***************************************************************************************************
* Description:  网络设置
***************************************************************************************************/
void Set_Net(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        break;
        case MENU_LEFT:
        break;
        case MENU_RIGHT:
        case MENU_ENTER:
        Menu->CreateList(stMenuItem_Net);
        Menu->ListApendItem(stMenuItem_Dhcp);
        Menu->ListApendItem(stMenuItem_IpAddr);
        Menu->ListApendItem(stMenuItem_NetMask);
        Menu->ListApendItem(stMenuItem_Gateway);
        Menu->Show();
        break;
    }
}
void Set_Dhcp(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stCamInfo.dhcp == VISCA_ON) stCamInfo.dhcp = VISCA_OFF;
        else stCamInfo.dhcp = VISCA_ON;
        cam_dhcp(stCamInfo.dhcp);
        break;
    }
    index = stCamInfo.dhcp == VISCA_ON ? ON : OFF;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[18], strOnOff[index], 3);
}

static uint32_t ip = 0;
static uint32_t mask = 0;
static uint32_t gateway = 0;
static uint8_t ip_buf[16] = "123.123.123.123";
static uint8_t ip_buf_tmp[16] = {0};
static uint8_t ip_index = 0;
static uint8_t blink = 0;

static void ip_index_left(void)
{
    if(ip_index > 0)
    {
        ip_index--;
        if(ip_index == 3 || ip_index == 7 || ip_index == 11)
            ip_index--;
    }
    else ip_index = 14;
}
static void ip_index_right(void)
{
    if(ip_index < 14)
    {
        ip_index++;
        if(ip_index == 3 || ip_index == 7 || ip_index == 11)
            ip_index++;
    }
    else ip_index = 0;
}
static void input_ip(uint8_t num)
{
    if(num > 9)
        return;
    
    switch(ip_index % 4)
    {
        case 0:
        if(num > 2) 
            return;
        ip_buf[ip_index] = num + '0';
        ip_buf[ip_index+1] = '0';
        ip_buf[ip_index+2] = '0';
        break;
        
        case 1:
        if((ip_buf[ip_index-1] >= (2 + '0')) && (num > 5))
            return;
        ip_buf[ip_index] = num + '0';
        ip_buf[ip_index+1] = '0';
        break;
        
        case 2:
        if((ip_buf[ip_index-2] >= (2 + '0')) && \
            (ip_buf[ip_index-1] >= (5 + '0')) && (num > 5))
            return;
        ip_buf[ip_index] = num + '0';
        break;
        
        default:
        break;
    }
    ip_index_right();
}

static uint32_t Str2Ip(const uint8_t *str)
{
    uint32_t ip;
    uint8_t temp;
    
    temp = (str[0] - '0') * 100;
    temp += (str[1]  - '0') * 10;
    temp += (str[2] - '0');
    ip = temp << 24;
    
    temp = (str[4] - '0') * 100;
    temp += (str[5] - '0') * 10;
    temp += (str[6] - '0');
    ip |= temp << 16;
    
    temp = (str[8] - '0') * 100;
    temp += (str[9] - '0') * 10;
    temp += (str[10] - '0');
    ip |= temp << 8;
    
    temp = (str[12] - '0') * 100;
    temp += (str[13] - '0') * 10;
    temp += (str[14] - '0');
    ip |= temp << 0;
    return ip;
}

void Set_IpAddr(int todo, MENU_LIST_ITEM_ST &this_item)
{
    if(stCamInfo.dhcp == VISCA_ON)
    {
        if(todo == MENU_REFRESH)
        {
            memcpy(&this_item.text[18], IpAddrToStr(stCamInfo.ip), 15);
        }
    }
    else
    {
        switch(todo)
        {
            case MENU_REFRESH:
            ip = stCamInfo.ip;
            memcpy(ip_buf, IpAddrToStr(ip), 15);
            memcpy(&this_item.text[18], ip_buf, 15);
            ip_index = 0;
            break;
            
            case MENU_TRIGGER:
            memcpy(ip_buf, IpAddrToStr(ip), 15);
            memcpy(ip_buf_tmp, ip_buf, 15); 
            if(blink) blink = 0;
            else blink = 1;
            if(blink) ip_buf[ip_index] = ' ';
            memcpy(&this_item.text[18], ip_buf, 15);
            Menu->ShowRow();
            memcpy(ip_buf, ip_buf_tmp, 15);
            break;
            
            case MENU_SELECT:
            ip_index = 0;
            break;
            
            case MENU_UP:
            case MENU_DOWN:
            case MENU_BACK:
            memcpy(&this_item.text[18], IpAddrToStr(ip), 15);
            Menu->ShowRow();
            stCamInfo.ip = ip;
            visca_set_net(YHW_NET_IP, stCamInfo.ip, 0);
            break;
            
            case MENU_ENTER: break;
            
            case MENU_LEFT:
            ip_index_left();
            break;
            
            case MENU_RIGHT:
            ip_index_right();
            break;
            
            default:
            input_ip(todo);
            memcpy(&this_item.text[18], ip_buf, 15);
            Menu->ShowRow();
            ip = Str2Ip(ip_buf);
            break;
        }
    }
}
void Set_NetMask(int todo, MENU_LIST_ITEM_ST &this_item)
{
    if(stCamInfo.dhcp == VISCA_ON)
    {
        if(todo == MENU_REFRESH)
        {
            memcpy(&this_item.text[18], IpAddrToStr(stCamInfo.mask), 15);
        }
    }
    else
    {
        switch(todo)
        {
            case MENU_REFRESH:
            mask = stCamInfo.mask;
            memcpy(ip_buf, IpAddrToStr(mask), 15);
            memcpy(&this_item.text[18], ip_buf, 15);
            ip_index = 0;
            break;
            
            case MENU_TRIGGER:
            memcpy(ip_buf, IpAddrToStr(mask), 15);
            memcpy(ip_buf_tmp, ip_buf, 15);
            if(blink) blink = 0;
            else blink = 1;
            if(blink) ip_buf[ip_index] = ' ';
            memcpy(&this_item.text[18], ip_buf, 15);
            Menu->ShowRow();
            memcpy(ip_buf, ip_buf_tmp, 15);
            break;
            
            case MENU_SELECT:
            ip_index = 0;
            break;
            
            case MENU_UP:
            case MENU_DOWN:
            case MENU_BACK:
            memcpy(&this_item.text[18], IpAddrToStr(mask), 15);
            Menu->ShowRow();
            stCamInfo.mask = mask;
            visca_set_net(YHW_NET_MASK, stCamInfo.mask, 0);
            break;
            
            case MENU_ENTER: break;
            
            case MENU_LEFT:
            ip_index_left();
            break;
            
            case MENU_RIGHT:
            ip_index_right();
            break;
            
            default:
            input_ip(todo);
            memcpy(&this_item.text[18], ip_buf, 15);
            Menu->ShowRow();
            mask = Str2Ip(ip_buf);
            break;
        }
    }
}
void Set_Gateway(int todo, MENU_LIST_ITEM_ST &this_item)
{
    if(stCamInfo.dhcp == VISCA_ON)
    {
        if(todo == MENU_REFRESH)
        {
            memcpy(&this_item.text[18], IpAddrToStr(stCamInfo.gateway), 15);
        }
    }
    else
    {
        switch(todo)
        {
            case MENU_REFRESH:
            gateway = stCamInfo.gateway;
            memcpy(ip_buf, IpAddrToStr(gateway), 15);
            memcpy(&this_item.text[18], ip_buf, 15);
            ip_index = 0;
            break;
            
            case MENU_TRIGGER:
            memcpy(ip_buf, IpAddrToStr(gateway), 15);
            memcpy(ip_buf_tmp, ip_buf, 15); 
            if(blink) blink = 0;
            else blink = 1;
            if(blink) ip_buf[ip_index] = ' ';
            memcpy(&this_item.text[18], ip_buf, 15);
            Menu->ShowRow();
            memcpy(ip_buf, ip_buf_tmp, 15);
            break;
            
            case MENU_SELECT:
            ip_index = 0;
            break;
            
            case MENU_UP:
            case MENU_DOWN:
            case MENU_BACK:
            memcpy(&this_item.text[18], IpAddrToStr(gateway), 15);
            Menu->ShowRow();
            stCamInfo.gateway = gateway;
            visca_set_net(YHW_NET_GATEWAY, stCamInfo.gateway, 0);
            break;
            
            case MENU_ENTER: break;
            
            case MENU_LEFT:
            ip_index_left();
            break;
            
            case MENU_RIGHT:
            ip_index_right();
            break;
            
            default:
            input_ip(todo);
            memcpy(&this_item.text[18], ip_buf, 15);
            Menu->ShowRow();
            gateway = Str2Ip(ip_buf);
            break;
        }
    }
}

/***************************************************************************************************
* Description:  系统设置
***************************************************************************************************/
void Set_SysSet(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        break;
        case MENU_LEFT:
        break;
        case MENU_RIGHT:
        case MENU_ENTER:
        Menu->CreateList(stMenuItem_SysSet);
        Menu->ListApendItem(stMenuItem_VideoFormat);
		Menu->ListApendItem(stMenuItem_HdmiOutColorSpace);
		Menu->ListApendItem(stMenuItem_HdmiMode);
        Menu->ListApendItem(stMenuItem_CallPreset1);
        Menu->ListApendItem(stMenuItem_Language);
        Menu->ListApendItem(stMenuItem_SwVersion);
        Menu->ListApendItem(stMenuItem_FactoryReset);
        Menu->Show();
        break;
    }
}
void Set_VideoFormat(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strVideoFormat[][13] = 
    {
        "            ",
        "320x240p60  ",
        "640x480p60  ",
        "800x600p30  ",
        "800x600p60  ",
        "1280x720p15 ",
        "1280x720p25 ",
        "1280x720p30 ",
        "1280x720p50 ",
        "1280x720p60 ",
        "1920x1080p25",
        "1920x1080p30",
        "1920x1080p50",
        "1920x1080p60",
        "1920x1080i50",
        "1920x1080i60",
        "1920x1080p29",
        "1920x1080p59",
        "1920x1080i59",
        "3840x2160p25",
        "3840x2160p30",
        "3840x2160p50",
        "3840x2160p60",
        "7680x4320p25",
        "7680x4320p30",
        "7680x4320p50",
        "7680x4320p60",
    };
    static uint8_t Temp;
    switch(todo)
    {
        case MENU_REFRESH:
        Temp = stSysInfo.video_format_out1;
        break;
        case MENU_LEFT:
        if(Temp > VIDEO_1280x720p50) Temp--;
        else Temp = VIDEO_1920x1080i59;
        break;
        case MENU_RIGHT:
        if(Temp < VIDEO_1920x1080i59) Temp++;
        else Temp = VIDEO_1280x720p50;
        break;
        case MENU_ENTER:
        if(Temp != stSysInfo.video_format_out1)
        {
            stSysInfo.video_format_out1 = Temp;
            SetMainVideoFormat(stSysInfo.video_format_out1);
            delay_ms(100);
            Menu->ShowFrame();
            Menu->Show();
            FPGA_OsdSwitch(ON);
        }
        break;
    }
    memcpy(&this_item.text[20], strVideoFormat[Temp], 12);
}
void Set_HdmiOutColorSpace(int todo, MENU_LIST_ITEM_ST &this_item)
{
	static uint8_t color_space_flag = 0;
	
    const uint8_t strColorSpace[][9] = 
    {
        "RGB     ",
        "YCbCr422",
    };
    switch(todo)
    {
        case MENU_REFRESH:
		color_space_flag = stSysInfo.color_space;
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(color_space_flag) color_space_flag = 0;
        else color_space_flag = 1;
        break;
		
		case MENU_ENTER:
		if(stSysInfo.color_space != color_space_flag)
		{
			stSysInfo.color_space = color_space_flag;
			SiI9022_SetOutColorSpace(stSysInfo.color_space);
			SetMainVideoFormat(stSysInfo.video_format_out1);
			delay_ms(100);
			Menu->ShowFrame();
			Menu->Show();
			FPGA_OsdSwitch(ON);
		}
        break;
    }
    
    memcpy(&this_item.text[20], strColorSpace[color_space_flag], 8);
}
void Set_HdmiMode(int todo, MENU_LIST_ITEM_ST &this_item)
{
	static uint8_t hdmi_mode_flag = 0;
	
    const uint8_t strHdmiMode[][5] = 
    {
        "HDMI",
        "DVI ",
    };
    switch(todo)
    {
        case MENU_REFRESH:
		hdmi_mode_flag = stSysInfo.hdmi_mode;
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(hdmi_mode_flag) hdmi_mode_flag = 0;
        else hdmi_mode_flag = 1;
        break;
		
		case MENU_ENTER:
		if(stSysInfo.hdmi_mode != hdmi_mode_flag)
		{
			stSysInfo.hdmi_mode = hdmi_mode_flag;
			SiI9022_SetOutHdmiMode(stSysInfo.hdmi_mode);
			SetMainVideoFormat(stSysInfo.video_format_out1);
			delay_ms(100);
			Menu->ShowFrame();
			Menu->Show();
			FPGA_OsdSwitch(ON);
		}
        break;
    }
    
    memcpy(&this_item.text[20], strHdmiMode[hdmi_mode_flag], 4);
}
void Set_CallPreset1(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stSysInfo.call_preset1 == ON) stSysInfo.call_preset1 = OFF;
        else stSysInfo.call_preset1 = ON;
        break;
    }
    index = stSysInfo.call_preset1;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[20], strOnOff[index], 3);
}
void Set_Language(int todo, MENU_LIST_ITEM_ST &this_item)
{
    const uint8_t strLanguage[3][9] = {
        "English ",
        "简体中文",
        "繁體中文",
    };
    static uint8_t Temp;
    switch(todo)
    {
        case MENU_REFRESH:
        Temp = stSysInfo.language;
        break;
        case MENU_LEFT:
        if(Temp == ENGLISH) Temp = ZH_TW;
        else Temp--;
        break;
        case MENU_RIGHT:
        if(Temp == ZH_TW) Temp = ENGLISH;
        else Temp++;
        break;
        case MENU_ENTER:
        if(Temp != stSysInfo.language)
        {
            stSysInfo.language = Temp;
            Menu->BackNoRefresh();
            OSD_Back();
            OSD_Open(1);            
        }
        break;
    }
    memcpy(&this_item.text[20], strLanguage[Temp], 8);
}
void Set_SwVersion(int todo, MENU_LIST_ITEM_ST &this_item)
{
    /* 工程模式开关 */
    if(todo == 7)
    {
        Menu->CreateList(stMenuItem_Factory);
        Menu->ListApendItem(stMenuItem_FactoryPattern);
        Menu->ListApendItem(stMenuItem_PresetSavePic);
        Menu->Show();
    }
    /* 打开机芯菜单 */
    else if(todo == 8)
    {
        if(stRunInfo.osd == OSD_ON)
        {
            stRunInfo.osd = OSD_CAM;
            FPGA_OsdSwitch(OFF);
            cam_menu_switch();
        }
    }
    /* 串口指令Debug */
    else if(todo == 9)
    {
        if(stRunInfo.osd == OSD_ON)
        {
            stRunInfo.osd = OSD_DEBUG;
            FPGA_OsdShowHexInit();
            CmdDebug(ON);
        }
    }
}
void Set_FactoryPattern(int todo, MENU_LIST_ITEM_ST &this_item)
{
    uint8_t index;
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(stRunInfo.factory_pattern == ON)
        {
            stRunInfo.refresh_mask = OFF;
            stRunInfo.factory_pattern = OFF;
            LED_STANDBY_OFF;
        }
        else
        {
            stRunInfo.refresh_mask = ON;
            stRunInfo.factory_pattern = ON;
        }
        LinkCam2In1(stRunInfo.factory_pattern);
        break;
    }
    index = stRunInfo.factory_pattern;
    index += Menu->getLanguageIndex() * 2;
    memcpy(&this_item.text[18], strOnOff[index], 3);
}
void Set_PresetSavePic(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        case MENU_ENTER:
        break;
        case MENU_LEFT:
        case MENU_RIGHT:
        if(PRESET_SAVE_PIC == ON) PRESET_SAVE_PIC = OFF;
        else PRESET_SAVE_PIC = ON;
        break;
    }
    memcpy(&this_item.text[18], strOnOff[PRESET_SAVE_PIC], 3);
}
void Set_CmdDebug(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        if(stRunInfo.osd == OSD_ON)
        {
            stRunInfo.osd = OSD_DEBUG;
            FPGA_OsdShowHexInit();
            CmdDebug(ON);
        }
        break;
        
        case MENU_BACK:
        CmdDebug(OFF);
        break;
        
        default:
        break;
    }
    
}

/***************************************************************************************************
* Description:  恢复出厂设置
***************************************************************************************************/
void Set_FactoryReset(int todo, MENU_LIST_ITEM_ST &this_item)
{
    switch(todo)
    {
        case MENU_REFRESH:
        break;
        case MENU_LEFT:
        break;
        case MENU_RIGHT:
        case MENU_ENTER:
        Menu->CreateList(stMenuItem_FactoryReset);
        Menu->ListApendItem(stMenuItem_ResetSystem);
        Menu->ListApendItem(stMenuItem_ResetPicture);
        Menu->ListApendItem(stMenuItem_ResetNet);
        Menu->ListApendItem(stMenuItem_ResetAll);
        Menu->Show();
        break;
    }
}
void Set_ResetSystem(int todo, MENU_LIST_ITEM_ST &this_item)
{
    if(todo == MENU_RIGHT || todo == MENU_ENTER)
    {
        FPGA_OsdShowLine(2, "                                    ");
        FPGA_OsdShowLine(3, "                                    ");
        FPGA_OsdShowLine(4, "                                    ");
        FPGA_OsdShowLine(5, "            Resetting...            ");
        System_ResetPara();
        delay_ms(2000);
        OSD_Back();
    }
}
void Set_ResetPicture(int todo, MENU_LIST_ITEM_ST &this_item)
{
    if(todo == MENU_RIGHT || todo == MENU_ENTER)
    {
        FPGA_OsdShowLine(2, "                                    ");
        FPGA_OsdShowLine(3, "                                    ");
        FPGA_OsdShowLine(4, "                                    ");
        FPGA_OsdShowLine(5, "            Resetting...            ");
        cam_reset_picture();
        delay_ms(2000);
        OSD_Back();
    }
}
void Set_ResetNet(int todo, MENU_LIST_ITEM_ST &this_item)
{
    if(todo == MENU_RIGHT || todo == MENU_ENTER)
    {
        FPGA_OsdShowLine(2, "                                    ");
        FPGA_OsdShowLine(3, "                                    ");
        FPGA_OsdShowLine(4, "                                    ");
        FPGA_OsdShowLine(5, "            Resetting...            ");
        cam_reset_net();
        delay_ms(2000);
        OSD_Back();
    }
}
void Set_ResetAll(int todo, MENU_LIST_ITEM_ST &this_item)
{
    if(todo == MENU_RIGHT || todo == MENU_ENTER)
    {
        FPGA_OsdShowLine(2, "                                    ");
        FPGA_OsdShowLine(3, "                                    ");
        FPGA_OsdShowLine(4, "                                    ");
        FPGA_OsdShowLine(5, "            Resetting...            ");
        cam_reset_picture();
        cam_reset_net();
        System_ResetPara();
        delay_ms(2000);
        OSD_Back();
    }
}

/***************************************************************************************************
* Description: 菜单上
***************************************************************************************************/
void OSD_Up(void)
{
    static uint32_t TimerUp = 0;
    if(!CheckInterval(&TimerUp, 300)) return;
    if(stRunInfo.osd == OSD_ON)
        Menu->Up();
    else if(stRunInfo.osd == OSD_CAM)
        cam_menu_up();
}

/***************************************************************************************************
* Description: 菜单下
***************************************************************************************************/
void OSD_Down(void)
{
    static uint32_t TimerDown = 0;
    if(!CheckInterval(&TimerDown, 300)) return;
    if(stRunInfo.osd == OSD_ON)
        Menu->Down();
    else if(stRunInfo.osd == OSD_CAM)
        cam_menu_down();
}

/***************************************************************************************************
* Description: 菜单左
***************************************************************************************************/
void OSD_Left(void)
{
    static uint32_t TimerLeft = 0;
    if(!CheckInterval(&TimerLeft, 300)) return;
    if(stRunInfo.osd == OSD_ON)
        Menu->Left();
    else if(stRunInfo.osd == OSD_CAM)
        cam_menu_left();
}

/***************************************************************************************************
* Description: 菜单右
***************************************************************************************************/
void OSD_Right(void)
{
    static uint32_t TimerRight = 0;
    if(!CheckInterval(&TimerRight, 300)) return;
    if(stRunInfo.osd == OSD_ON)
        Menu->Right();
    else if(stRunInfo.osd == OSD_CAM)
        cam_menu_right();
}

/***************************************************************************************************
* Description: 确定
***************************************************************************************************/
void OSD_Enter(void)
{
    static uint32_t TimerEnter = 0;
    if(!CheckInterval(&TimerEnter, 300)) return;
    if(stRunInfo.osd == OSD_ON)
        Menu->Enter();
}

/***************************************************************************************************
* Description: 菜单返回
***************************************************************************************************/
void OSD_Back(void)
{
    static uint32_t TimerBack = 0;
    if(!CheckInterval(&TimerBack, 300)) return;
    
    if(stRunInfo.osd == OSD_ON)
    {
        if(Menu->Back())
        {
            stRunInfo.osd = OSD_OFF;
            FPGA_OsdSwitch(OFF);
            Ptc_Init();
            visca_custom_set();
            System_SavePara();
            CalPtzSpeed();
            delete Menu;
            Menu = NULL;
        }
    }
    else if(stRunInfo.osd == OSD_CAM)
    {
        stRunInfo.osd = OSD_ON;
        cam_menu_switch();
        FPGA_OsdSwitch(ON);
    }
    else if(stRunInfo.osd == OSD_DEBUG)
    {
        stRunInfo.osd = OSD_ON;
        CmdDebug(OFF);
        FPGA_OsdClear();
        Menu->ShowFrame();
        Menu->Show();
    }
}

/***************************************************************************************************
* Description: 打开菜单
***************************************************************************************************/
void OSD_Open(uint8_t arg)
{
    static uint32_t TimerOpen = 0;
    if(!CheckInterval(&TimerOpen, 300)) return;
    if(stRunInfo.osd == OSD_OFF)
    {
        if(arg != 1)
            return;
        stRunInfo.osd = OSD_ON;
        FPGA_OsdClear();
        
        Menu = new MENU((LANGUAGE_E)stSysInfo.language);
        
        Menu->CreateList(stMenuName_Main);
        Menu->ListApendItem(stMenuItem_GotoCom);
        Menu->ListApendItem(stMenuItem_GotoPtz);
        Menu->ListApendItem(stMenuItem_Exposure);
        Menu->ListApendItem(stMenuItem_Wb);
        Menu->ListApendItem(stMenuItem_Picture);
        Menu->ListApendItem(stMenuItem_Net);
        Menu->ListApendItem(stMenuItem_SysSet);
        
        Menu->Show();
        
        FPGA_OsdSwitch(ON);
    }
    else if(stRunInfo.osd == OSD_ON)
    {
        Menu->RunFunc(MENU_BACK);
    }
}
/***************************************************************************************************
* Description:  
***************************************************************************************************/
void OSD_Num(uint8_t num)
{
    if(num > 9)
        return;
    
    Menu->RunFunc(num);
}


void OSD_Task(void)
{
    static uint32_t timer_osd = 0;
    
    if(stRunInfo.osd == OSD_OFF) return;
    if(!CheckInterval(&timer_osd, 200)) return;
    
    Menu->RunFunc(MENU_TRIGGER);
    
}

/****************************************** END OF FILE *******************************************/
