#include "Village.h"
#include "InputManager.h"
#include "CursorManager.h"

Village::Village(): dwkey(0)
{
}

Village::~Village()
{
}

void Village::Start()
{
    Ground.Buffer[0] = (char*)"-----------------------------------------------------------------------------------------------------------------------------------------------------";

    Ground.Length = strlen("-----------------------------------------------------------------------------------------------------------------------------------------------------");
    Ground.MaxSize = 1;
    Ground.Color = 15;

}

void Village::Update()
{
    dwkey = InputManager::GetInstance()->GetKey();

}

void Village::Render()
{
   // for (int i = 0; i < Ground.MaxSize; ++i)
    //{
        CursorManager::GetInstance()->WriteBuffer(0.0f, 45.0f,
            Ground.Buffer[0], Ground.Color);
   // }
}

void Village::Release()
{
}
