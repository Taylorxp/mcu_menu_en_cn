/***************************************************************************************************
* FILE: menu_framework.h

* DESCRIPTION:  --

****************************************************************************************************
* MODIFY:  --

* DESCRIPTION: --

* DATE: --
***************************************************************************************************/
#ifndef __MENU_FRAMEWORK_H
#define __MENU_FRAMEWORK_H
/***************************************************************************************************
* INCLUDE
***************************************************************************************************/
#include <list>
#include <string>
#include <stdint.h>

//#ifdef __cplusplus
// extern "C" {
//#endif
/***************************************************************************************************
* DEFINE
***************************************************************************************************/

#define MENU_REFRESH    (uint8_t)(-1)
#define MENU_TRIGGER    (uint8_t)(-2)
#define MENU_UP         (uint8_t)(-3)
#define MENU_DOWN       (uint8_t)(-4)
#define MENU_LEFT       (uint8_t)(-5)
#define MENU_RIGHT      (uint8_t)(-6)
#define MENU_SELECT     (uint8_t)(-7)
#define MENU_ENTER      (uint8_t)(-8)
#define MENU_BACK       (uint8_t)(-9)

/* 错误代码 */
#define JT_SUCCESS  1
#define JT_ERR_NO_ERR 0
#define JT_ERR_NULL_PTR -1
#define JT_ERR_MALLOC_FAIL -2




typedef enum en_language
{
    ENGLISH,
    CHINESE,
    ZH_TW,
}LANGUAGE_E;

typedef struct st_list_item
{
    void (*func)(int todo, struct st_menu_list_item &this_item);
    uint8_t text[3][37];
}LIST_ITEM_ST;          //一个内菜单条目所具有的属性

typedef struct st_menu_list_item
{
    void (*func)(int todo, struct st_menu_list_item &this_item);
    uint8_t text[37];
}MENU_LIST_ITEM_ST;     //一个菜单条目所具有的属性

class MenuList
{
    private:
    uint8_t u8CursorPos;        //光标位置
    uint8_t u8ItemCount;        //条目位置
    
    public:
    uint8_t ListName[37];       //条目名称
    list<MENU_LIST_ITEM_ST> ListItem;       //条目链表
    list<MENU_LIST_ITEM_ST>::iterator it;
    
    MenuList(const uint8_t (&str)[37]);     //构造函数
    ~MenuList();                            //析构函数
    /*构造菜单函数*/
    void AddItem(MENU_LIST_ITEM_ST &list_item); //添加条目
    /*显示函数*/
    void ShowCursor(void);
    void ShowRow(void);
    void ShowStringAtCurrentRow(const uint8_t *str);
    uint8_t *GetCurrentRowTextBuffer(void);
    void Show(void);
    /*动作函数*/
    void Enter(void);
    void Up(void);
    void Down(void);
    void Left(void);
    void Right(void);
};

class MENU
{
    private:
    LANGUAGE_E eLanguage;
    
    list<MenuList*> MenuStackList;  //调用栈
    
    public:
    
    MenuList *pMenuList;            //列表指针
    
    MENU();
    MENU(LANGUAGE_E lang);
    ~MENU();
    
    uint8_t getLanguageIndex(void);
    
    void ShowFrame(void);
    void CreateList(const LIST_ITEM_ST& listname);
    void ListApendItem(const LIST_ITEM_ST &listitem);
    
    void ShowStringAtCurrentRow(const uint8_t *str);
    void ShowRow(void);
    void Show(void);
    void Up(void);
    void Down(void);
    void Left(void);
    void Right(void);
    void Enter(void);
    void RunFunc(uint8_t todo);
    
    bool Back(void);
    bool BackNoRefresh(void);
    
};


//#define OSD_Up      MDIN_OSD_Up
//#define OSD_Down    MDIN_OSD_Down
//#define OSD_Left    MDIN_OSD_Left
//#define OSD_Right   MDIN_OSD_Right
//#define OSD_Enter   MDIN_OSD_Enter
//#define OSD_Back    MDIN_OSD_Back
//#define OSD_Open    MDIN_OSD_Menu
/***************************************************************************************************
* VARIABLE
***************************************************************************************************/
extern MENU *Menu;


/***************************************************************************************************
* FUNCTION
***************************************************************************************************/
void MENU_Enter(void);

void MENU_Init(void);



void OSD_Up(void);
void OSD_Down(void);
void OSD_Left(void);
void OSD_Right(void);
void OSD_Enter(void);
void OSD_Back(void);
void OSD_Open(uint8_t arg);
void OSD_Num(uint8_t num);

void OSD_Task(void);

//#ifdef __cplusplus
//}
//#endif
#endif
/****************************************** END OF FILE *******************************************/
