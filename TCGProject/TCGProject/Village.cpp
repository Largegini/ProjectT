#include "Village.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "ObjectFactory.h"
#include "Player.h"
#include "MapManager.h"
#include "Portal_01.h"

Village::Village(): dwkey(0), _Player(nullptr), _Portal1(nullptr), _Portal2(nullptr)
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
    Quest.Color = 7;
    Quest.VectorInfo.Position = Vector3(5.0f, 28.0f);
    Quest.VectorInfo.Rotation = Vector3(0.0f, 0.0f);
    Quest.VectorInfo.Scale = Vector3((float)Quest.Length, (float)Quest.MaxSize);

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
    Store.Color = 7;
    Store.VectorInfo.Position = Vector3(80.0f, 26.0f);
    Store.VectorInfo.Rotation = Vector3(0.0f, 0.0f);
    Store.VectorInfo.Scale = Vector3(float(Store.Length), float(Store.MaxSize));

    Ground.Buffer[0] = (char*)"-----------------------------------------------------------------------------------------------------------------------------------------------------";
    Ground.Buffer[1] = (char*)"           '           `        *    ``        '        *          '               ``        '            `      ''      *          `*            '  ";
    Ground.Buffer[2] = (char*)"         이동    '            *           `       '      '         ``      ''      '        '         '          `    `         '     '       ` `   '";
    Ground.Buffer[3] = (char*)"      ___    ___                                                                                                                                     ";
    Ground.Buffer[4] = (char*)"     |   |  |   |                                                                                                                                    ";
    Ground.Buffer[5] = (char*)"     | < |  | > |                                                                                                                                    ";
    Ground.Buffer[6] = (char*)"     |___|  |___|                                                                                                                                    ";

    Ground.Length = strlen("-----------------------------------------------------------------------------------------------------------------------------------------------------");
    Ground.MaxSize = 7;
    Ground.Color = 7;
    Ground.VectorInfo.Position = Vector3(0.0f, 0.0f);
    Ground.VectorInfo.Rotation = Vector3(0.0f, 0.0f);
    Ground.VectorInfo.Scale = Vector3(0.0f, 0.0f);

    Key.Buffer[0] = (char*)" ___          ";
    Key.Buffer[1] = (char*)"|   |         ";
    Key.Buffer[2] = (char*)"| ^ | 들어가기";
    Key.Buffer[3] = (char*)"|___|         ";
    Key.Length = strlen("| ^ | 들어가기");
    Key.MaxSize = 4;
    Key.Color = 8;

    _Player = ObjectFactory<Player>::CreateObject();

    _Portal1 = ObjectFactory<Portal_01>::CreateObject();

    _Portal2 = ObjectFactory<Portal_01>::CreateObject(106.0f,40.0f);
}

void Village::Update()
{
    dwkey = InputManager::GetInstance()->GetKey();
    _Player->Update();
    
   
    if (CollisionManager::RectCollision(_Portal2->GetTransform(), 
        _Player->GetTransform()) )
    {
        if (dwkey & KEY_UP)
            MapManager::GetInstance()->SetMap(MapID::STORE);
    }

    if (CollisionManager::RectCollision(_Portal1->GetTransform(),
        _Player->GetTransform()))
    {

        if (dwkey & KEY_UP)
            MapManager::GetInstance()->SetMap(MapID::GUILD);
    }
}

void Village::Render()
{

    for (int i = 0; i < Store.MaxSize; ++i)
    {
        CursorManager::GetInstance()->WriteBuffer(Store.VectorInfo.Position.x
            , Store.VectorInfo.Position.y + i, Store.Buffer[i], Store.Color);
    }

    for (int i = 0; i < Quest.MaxSize; ++i)
    {
        CursorManager::GetInstance()->WriteBuffer(Quest.VectorInfo.Position.x,
            Quest.VectorInfo.Position.y + i, Quest.Buffer[i], Quest.Color);
    }

    for (int i = 0; i < Ground.MaxSize; ++i)
    {
        CursorManager::GetInstance()->WriteBuffer(0.0f, 45.0f+i,
            Ground.Buffer[i], Ground.Color);
    }

    if (CollisionManager::RectCollision(_Portal1->GetTransform(), 
        _Player->GetTransform()) )
    {
        for (int i = 0; i < Key.MaxSize; ++i)
        {
            CursorManager::GetInstance()->WriteBuffer(Quest.VectorInfo.Position.x +
                (Quest.Length / 2) - (Key.Length/2), 35.0f + i, 
                Key.Buffer[i], Key.Color);
        }
    }

    if (CollisionManager::RectCollision(_Portal2->GetTransform(), 
        _Player->GetTransform()) )
    {
        for (int i = 0; i < Key.MaxSize; ++i)
        {
            CursorManager::GetInstance()->WriteBuffer(Store.VectorInfo.Position.x +
                (Store.Length / 2) - (Key.Length / 2), 35.0f + i,
                Key.Buffer[i], Key.Color);
        }
    }
    _Player->Render();

    if (dwkey & KEY_E)
    {
        _Portal1->Render();
        _Portal2->Render();
    }
}

void Village::Release()
{
    delete _Player;
    _Player = nullptr;

    delete _Portal1;
    _Portal1 = nullptr;
}
