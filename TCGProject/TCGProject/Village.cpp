#include "Village.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Player.h"

Village::Village(): dwkey(0), _Player(nullptr)
{
}

Village::~Village()
{
    Release();
}

void Village::Start()
{
    Quest.Buffer[0] =  (char*)"          ##########################################         ";
    Quest.Buffer[1] =  (char*)"         ##                                        ##        ";
    Quest.Buffer[2] =  (char*)"        ##   ----          _________          ___   ##       ";
    Quest.Buffer[3] =  (char*)"       ##                 [ [     ] ]     __         ##      ";
    Quest.Buffer[4] =  (char*)"      ##          ----     [ [   ] ]                  ##     ";
    Quest.Buffer[5] =  (char*)"     ##                    [ '___' ]                   ##    ";
    Quest.Buffer[6] =  (char*)"    ##       -----          `-----'          ____       ##   ";
    Quest.Buffer[7] =  (char*)"   ##                                                    ##  ";
    Quest.Buffer[8] =  (char*)"  ##___    ____   _____    ______  _______   ____   __ ___## ";     
    Quest.Buffer[9] =  (char*)"       ┃    _______        ______        _______     ┃     ";
    Quest.Buffer[10] = (char*)"       ┃   (   |   )      | 길드 |      (   |   )    ┃     ";
    Quest.Buffer[11] = (char*)"       ┃   |___|___|      |______|      |___|___|    ┃     ";
    Quest.Buffer[12] = (char*)"       ┃   |   |   |    ____________    |   |   |    ┃     ";
    Quest.Buffer[13] = (char*)"       ┃   |---|---|   |      !     |   |---|---|    ┃     ";
    Quest.Buffer[14] = (char*)"       ┃   |___|___|   |      !     |   |___|___|    ┃     ";
    Quest.Buffer[15] = (char*)"       ┃               |     o!o    |                ┃     ";
    Quest.Buffer[16] = (char*)"       ┃               |      !     |                ┃     ";

    Quest.Length = strlen("  ##___    ____   _____    ______  _______   ____   __ ___## ");
    Quest.MaxSize = 17;
    Quest.Color = 15;

    Store.Buffer[0]  = (char*)"      ###################################################      ";
    Store.Buffer[1]  = (char*)"     ##   _____                                         ##     ";
    Store.Buffer[2]  = (char*)"    ##         ____           ######    ____             ##    ";
    Store.Buffer[3] =  (char*)"   ##  ______                #     ##                     ##   ";
    Store.Buffer[4] =  (char*)"  ##       _____            #                _____         ##  ";
    Store.Buffer[5] =  (char*)" ##                ______   #   #####   ____                ## ";
    Store.Buffer[6] =  (char*)"##     _______              #   ####         __              ##";
    Store.Buffer[7] =  (char*)"#                _______     #### ##            ________      #";
    Store.Buffer[8]  = (char*)"#                                                             #";
    Store.Buffer[9]  = (char*)"#_______   ___   __     ________  ___    ____   __  __________#";
    Store.Buffer[10] = (char*)"       ┃                                             ┃       ";
    Store.Buffer[11] = (char*)"       ┃    _______        ______        _______     ┃       ";
    Store.Buffer[12] = (char*)"       ┃   (   |   )      | 상점 |      (   |   )    ┃       ";
    Store.Buffer[13] = (char*)"       ┃   |___|___|      |______|      |___|___|    ┃       ";
    Store.Buffer[14] = (char*)"       ┃   |   |   |    ____________    |   |   |    ┃       ";
    Store.Buffer[15] = (char*)"       ┃   |---|---|   |      !     |   |---|---|    ┃       ";
    Store.Buffer[16] = (char*)"       ┃   |___|___|   |      !     |   |___|___|    ┃       ";
    Store.Buffer[17] = (char*)"       ┃               |     o!o    |                ┃       ";
    Store.Buffer[18] = (char*)"       ┃               |      !     |                ┃       ";

    Store.Length = strlen("#_______   ___   __     ________  ___    ____   __  __________#");
    Store.MaxSize = 19;
    Store.Color = 15;

    Ground.Buffer[0] = (char*)"-----------------------------------------------------------------------------------------------------------------------------------------------------";
    Ground.Buffer[1] = (char*)"           '           `        *    ``        '        *          '               ``        '            `      ''      *          `*            '  ";
    Ground.Buffer[2] = (char*)"         이동    '            *           `       '      '         ``      ''      '        '         '          `    `         '     '       ` `   '";
    Ground.Buffer[3] = (char*)"      ___    ___                                                                                                                                     ";
    Ground.Buffer[4] = (char*)"     |   |  |   |                                                                                                                                    ";
    Ground.Buffer[5] = (char*)"     | < |  | > |                                                                                                                                    ";
    Ground.Buffer[6] = (char*)"     |___|  |___|                                                                                                                                    ";

    Ground.Length = strlen("-----------------------------------------------------------------------------------------------------------------------------------------------------");
    Ground.MaxSize = 7;
    Ground.Color = 15;

    _Player = new Player;
    _Player->Start();
}

void Village::Update()
{
    dwkey = InputManager::GetInstance()->GetKey();
    _Player->Update();
}

void Village::Render()
{

    for (int i = 0; i < Store.MaxSize; ++i)
    {
        CursorManager::GetInstance()->WriteBuffer(80.0f, 26.0f + i,
            Store.Buffer[i], Store.Color);
    }

    for (int i = 0; i < Quest.MaxSize; ++i)
    {
        CursorManager::GetInstance()->WriteBuffer(5.0f, 28.0f + i,
            Quest.Buffer[i], Quest.Color);
    }

    for (int i = 0; i < Ground.MaxSize; ++i)
    {
        CursorManager::GetInstance()->WriteBuffer(0.0f, 45.0f+i,
            Ground.Buffer[i], Ground.Color);
    }
    _Player->Render();
}

void Village::Release()
{
    delete _Player;
    _Player = nullptr;
}
