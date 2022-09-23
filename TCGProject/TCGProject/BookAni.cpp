#include "BookAni.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "MapManager.h"

BookAni::BookAni() : Index(0), delay(0), dwkey(0), CursorPos(0)
{
}

BookAni::~BookAni()
{
}

void BookAni::Start()
{       
    Book.Buffer[0] =  (char*)"¦£-------------------------------------------------------------¦¤";
    Book.Buffer[1] =  (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[2] =  (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[3] =  (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[4] =  (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[5] =  (char*)"(¦¢     :'#######::'##::::'##:'########::'######::'########:   ¦¢";
    Book.Buffer[6] =  (char*)"(¦¢     '##.... ##: ##:::: ##: ##.....::'##... ##:... ##..::   ¦¢";
    Book.Buffer[7] =  (char*)"(¦¢     :##:::: ##: ##:::: ##: ##::::::: ##:::..::::: ##::::   ¦¢";
    Book.Buffer[8] =  (char*)"(¦¢     :##:::: ##: ##:::: ##: ######:::. ######::::: ##::::   ¦¢";
    Book.Buffer[9] =  (char*)"(¦¢     :##:'## ##: ##:::: ##: ##...:::::..... ##:::: ##::::   ¦¢";
    Book.Buffer[10] = (char*)"(¦¢     :##:.. ##:: ##:::: ##: ##:::::::'##::: ##:::: ##::::   ¦¢";
    Book.Buffer[11] = (char*)"(¦¢     : ##### ##:. #######:: ########:. ######::::: ##::::   ¦¢";
    Book.Buffer[12] = (char*)"(¦¢     :.....:..:::.......:::........:::......::::::..:::::   ¦¢";
    Book.Buffer[13] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[14] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[15] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[16] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[17] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[18] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[19] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[20] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[21] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[22] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[23] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[24] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[25] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[26] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[27] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[28] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[29] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[30] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[31] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[32] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[33] = (char*)"(¦¢                                                            ¦¢";
    Book.Buffer[34] = (char*)"¦¦-------------------------------------------------------------¦¥";
    Book.Length = strlen("(¦¢     :##:::: ##: ##:::: ##: ##::::::: ##:::..::::: ##::::   ¦¢");
    Book.MaxSize = 35;
    Book.Color = 7;
    Book.VectorInfo.Position = Vector3(30.0f, 15.0f);

    Book2.Buffer[0] =  (char*)"               /|                                                ";
    Book2.Buffer[1] =  (char*)"              / ¦¢/|                                             ";
    Book2.Buffer[2] =  (char*)"             /  ¦¢¦¢/|                                           ";
    Book2.Buffer[3] =  (char*)"            /   ¦¢¦¢¦¢/|                                         ";
    Book2.Buffer[4] =  (char*)"           /    ¦¢¦¢¦¢¦¢ /|                                      ";
    Book2.Buffer[5] =  (char*)"          /     ¦¢¦¢¦¢¦¢/¦¢/¦¢                                   "; 
    Book2.Buffer[6] =  (char*)"         /      ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                                   ";
    Book2.Buffer[7] =  (char*)"        /       ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                                   ";
    Book2.Buffer[8] =  (char*)"       /        ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                                   ";
    Book2.Buffer[9] =  (char*)"      /    #    ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                                   ";
    Book2.Buffer[10] = (char*)"     /    ##    ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                                   ";
    Book2.Buffer[11] = (char*)"    /    ###    ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                                   ";
    Book2.Buffer[12] = (char*)"   /    ####    ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                                   ";
    Book2.Buffer[13] = (char*)"  /    ####     ¦¢¦¢¦¢¦¢ ¦¢ ¦¢---------------------------------¦¤";
    Book2.Buffer[14] = (char*)"(¦¢   ####      ¦¢¦¢¦¢¦¢ ¦¢ ¦¢------------------------------ ¦¤¦¢";
    Book2.Buffer[15] = (char*)"(¦¢   ###       ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[16] = (char*)"(¦¢   ##        ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[17] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[18] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[19] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[20] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[21] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[22] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[23] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[24] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[25] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[26] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[27] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[28] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[29] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[30] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[31] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[32] = (char*)"(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[33] = (char*)"(¦¢             / ¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[34] = (char*)"(¦¢            /  / ¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[35] = (char*)"(¦¢           /  /  / ¦¢ ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[36] = (char*)"(¦¢          /  /  /  /  ¦¢ ¦¢                               ¦¢¦¢";
    Book2.Buffer[37] = (char*)"(¦¢         /  /  /  /   /  ¦¢                               ¦¢¦¢";
    Book2.Buffer[38] = (char*)"(¦¢        /  /  /  /   /   /                                ¦¢¦¢";
    Book2.Buffer[39] = (char*)"(¦¢       /  /  /  /   /   /                                 ¦¢¦¢";
    Book2.Buffer[40] = (char*)"(¦¢      /  /  /  /   /   /                                  ¦¢¦¢";
    Book2.Buffer[41] = (char*)"(¦¢     /  /  /  /   /   /                                   ¦¢¦¢";
    Book2.Buffer[42] = (char*)"(¦¢    /  /  /  /   /   /                                    ¦¢¦¢";
    Book2.Buffer[43] = (char*)"(¦¢   /  /  /  /   /_________________________________________¦¢¦¢";
    Book2.Buffer[44] = (char*)"(¦¢  /  /  /  / _______________________________________________¦¢";
    Book2.Buffer[45] = (char*)"(¦¢ /  /  / ___________________________________________________¦¢";
    Book2.Buffer[46] = (char*)"(¦¢/ _________________________________________________________ ¦¢";
    Book2.Buffer[47] = (char*)"¦¦-------------------------------------------------------------¦¥";
    Book2.Length = strlen("(¦¢             ¦¢¦¢¦¢¦¢ ¦¢ ¦¢                               ¦¢¦¢");
    Book2.MaxSize = 48;
    Book2.Color = 7;
    Book2.VectorInfo.Position = Vector3(146.0f-Book.Length, 2.0f);

    OpenBook.Buffer[0] =  (char*)"¦£-------------------------------------------------------------------------------------------------------------------¦¤";
    OpenBook.Buffer[1] =  (char*)"¦¢¦£-----------------------------------------------------¡Ò¡Ò------------------------------------------------------¦¤¦¢";
    OpenBook.Buffer[2] =  (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[3] =  (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[4] =  (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[5] =  (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[6] =  (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[7] =  (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[8] =  (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[9] =  (char*)"¦¢¦¢                                                      ¦¢            ¡Ú         µ¿±¼¹ö¼¸ ³³Ç°                   ¦¢¦¢";
    OpenBook.Buffer[10] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[11] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[12] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[13] = (char*)"¦¢¦¢                                                      ¦¢           ¡Ú¡Ú        ½½¶óÀÓ ÄÚ¾î È¸¼ö                ¦¢¦¢";
    OpenBook.Buffer[14] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[15] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[16] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[17] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[18] = (char*)"¦¢¦¢                                                      ¦¢          ¡Ú¡Ú¡Ú       ÁöÇÏÀ¯Àû Å½»ö                   ¦¢¦¢";
    OpenBook.Buffer[19] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[20] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[21] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[22] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[23] = (char*)"¦¢¦¢                                                      ¦¢         ¡Ú¡Ú¡Ú¡Ú      °íºí¸° Å· Åä¹ú                  ¦¢¦¢";
    OpenBook.Buffer[24] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[25] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[26] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[27] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[28] = (char*)"¦¢¦¢                                                      ¦¢        ¡Ú¡Ú¡Ú¡Ú¡Ú     ¿ÀÅ© ¾ß¿µÁö ÆÄ±«                ¦¢¦¢";
    OpenBook.Buffer[29] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[30] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[31] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[32] = (char*)"¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢";
    OpenBook.Buffer[33] = (char*)"¦¢¦¦-----------------------------------------------------¡Ò¡Ò------------------------------------------------------¦¥¦¢";
    OpenBook.Buffer[34] = (char*)"¦¦-------------------------------------------------------------------------------------------------------------------¦¥";
    OpenBook.Length = strlen("¦¢¦¢                                                      ¦¢                                                       ¦¢¦¢");
    OpenBook.MaxSize = 35;
    OpenBook.Color = 7;
    OpenBook.VectorInfo.Position = Vector3(30.0f, 15.0f);

    Cursor.Buffer[0] = (char*)"===¢º";
    Cursor.Buffer[1] = (char*)"                   ==================";
    Cursor.Length = strlen("===¢º");
    Cursor.MaxSize = 2;
    Cursor.Color = 12;
    Cursor.VectorInfo.Position = Vector3(97.0f, 0.0f);
}

MapID BookAni::Update()
{
    dwkey = InputManager::GetInstance()->GetKey();

    if (Book.VectorInfo.Position.x + Book.Length < 146)
        Book.VectorInfo.Position.x += 4;

    else if (Book.VectorInfo.Position.x + Book.Length > 145 && delay < 8)
    {
        Index = 1;
        delay++;
    }

    else if (delay >= 8)
    {
        Index = 2;
    }

    if (Index == 2)
    {
        if (dwkey & KEY_UP)
        {
            if (CursorPos > 0)
                CursorPos--;
        }

        if (dwkey & KEY_RETURN)
        {
            switch (CursorPos)
            {
            case 0:
                return MapID::DUNGEON1;
                break;
            case 1:

                //MapManager::GetInstance()->SetMap(MapID::DUNGEON2);
                break;
            case 2:
               // MapManager::GetInstance()->SetMap(MapID::DUNGEON3);
                break;
            case 3:
                //MapManager::GetInstance()->SetMap(MapID::DUNGEON4);
                break;
            case 4:
                //MapManager::GetInstance()->SetMap(MapID::DUNGEON5);
                break;
            default:
                break;
            } 
        }

        if (dwkey & KEY_DOWN)
        {
            if (CursorPos < 4)
                CursorPos++;
        }
    }
    return MapID::GUILD;
}

void BookAni::Render()
{
    switch (Index)
    {
        case 0:
            {
                for (int i = 0; i < Book.MaxSize; ++i)
                {
                    CursorManager::GetInstance()->WriteBuffer(Book.VectorInfo.Position.x,
                        Book.VectorInfo.Position.y + i, Book.Buffer[i], Book.Color);
                }
                 break;
            }
        case 1:
            {
                for (int i = 0; i < Book2.MaxSize; ++i)
                {
                    CursorManager::GetInstance()->WriteBuffer(Book.VectorInfo.Position.x,
                        Book2.VectorInfo.Position.y + i, Book2.Buffer[i], Book2.Color);
                }
                break;
            }
        case 2:
            {
                for (int i = 0; i < OpenBook.MaxSize; ++i)
                {
                    CursorManager::GetInstance()->WriteBuffer(OpenBook.VectorInfo.Position.x,
                        OpenBook.VectorInfo.Position.y + i, OpenBook.Buffer[i], OpenBook.Color);
                }
                break;
            }
    }

    if (Index == 2)
    {
        switch (CursorPos)
        {
        case 0:
            for (int i=0; i < Cursor.MaxSize; ++i)
            {
                CursorManager::GetInstance()->WriteBuffer(Cursor.VectorInfo.Position.x - Cursor.Length,
                    24.0f+i, Cursor.Buffer[i], Cursor.Color);
            }
            break;
        case 1:
            for (int i=0; i < Cursor.MaxSize; ++i)
            {
                CursorManager::GetInstance()->WriteBuffer(Cursor.VectorInfo.Position.x - Cursor.Length,
                    28.0f+i, Cursor.Buffer[i], Cursor.Color);
            }
                break;
        case 2:
            for (int i=0; i < Cursor.MaxSize; ++i)
            {
                CursorManager::GetInstance()->WriteBuffer(Cursor.VectorInfo.Position.x - Cursor.Length,
                    33.0f+i, Cursor.Buffer[i], Cursor.Color);
            }
                break;
        case 3:
            for (int i=0; i < Cursor.MaxSize; ++i)
            {
                CursorManager::GetInstance()->WriteBuffer(Cursor.VectorInfo.Position.x - Cursor.Length,
                    38.0f+i, Cursor.Buffer[i], Cursor.Color);
            }
                break;
        case 4:
            for (int i=0; i < Cursor.MaxSize; ++i)
            {
                CursorManager::GetInstance()->WriteBuffer(Cursor.VectorInfo.Position.x - Cursor.Length,
                    43.0f+i, Cursor.Buffer[i], Cursor.Color);
            }
                break;
        default:
            break;
        }
    }
}

void BookAni::Release()
{
}
