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
    
  Quest.Buffer[0] = (char*)" `                ##`                                      ##`                     ##` `                   ``##`   ##`   ";
  Quest.Buffer[1] = (char*)"############      ##`       #################`            ##`       #######` `    `##` `   #############   ``##     `##  ";
  Quest.Buffer[2] = (char*)"        `##` `    ##`       ##```          ``           `##``     ###`    ###`    `##`      `        `##   ``##`   ``### ";
  Quest.Buffer[3] = (char*)"      ``##`       ##`       ##`                         ##`    ``###       `##    `##`     ` `````````##   ``##`   ` `###";
  Quest.Buffer[4] = (char*)"     `##` `       ##`       ##`                       ``##     ` ##``      `##    `##`     #############   ``##`      `##";
  Quest.Buffer[5] = (char*)" `####`   `       ##`       ##`                        ###     ```##       `##    `##`     ##`       ` `   ``##`       ##";
  Quest.Buffer[6] = (char*)"`#```  ``````````````       ###```````````````         ###`       ###` ```###`    `##`     ##`        `    ``##`      `##";
  Quest.Buffer[7] = (char*)"  ` ################`      ```````````````````       ` ###`       ` `#####`       `##`     #############   ``##`      `##";
  Quest.Buffer[8] = (char*)"   `              ##       ` `             `         ` `##`        ``  ` ``       `##`      `  ``##`` `    ``##`      `##";
  Quest.Buffer[9] = (char*)"  `   `           ##    `                     ` ``    ` ##``   ``    `  ` `  ```#``##`  `````````##``######``##`   `` ###";
  Quest.Buffer[10] = (char*)"    ################    `########################`    ```##` ` `############````  `##`   ````````````  ` ````##    ``### ";
  Quest.Buffer[11] = (char*)"    ##``           `      `                   ````      ``## ``          `        `##`                     ``##    ``##` ";
  Quest.Buffer[12] = (char*)"  ` #################                                    ` `#`                     ##`                      `##    ##`   ";

  Quest.Length = strlen(" `                ##`                                      ##`                     ##` `                   ``##`   ##`   ");
  Quest.MaxSize = 13;
  Quest.Color = 15;

 Store.Buffer[0] = (char*)"        `      ````##`                      `##";   
 Store.Buffer[1] = (char*)"      ###         `##     `############`     ##";   
 Store.Buffer[2] = (char*)"      ##`         `##     ``    ##`    `     ##";   
 Store.Buffer[3] = (char*)"    `####`        `######      ###`` ` ########";   
 Store.Buffer[4] = (char*)" ` ``##`##`  ``   `##    ` ```#####`` ` `   `##";   
 Store.Buffer[5] = (char*)" ``##``  ###` `   `##   ``` `##`` `###`` ``` ##";   
 Store.Buffer[6] = (char*)"###`       `##`   `##    `###`      `###`    ##";   
 Store.Buffer[7] = (char*)"   ```  ` ``    `````        ``                ";   
 Store.Buffer[8] = (char*)"    ` `############ `       `  ################";   
 Store.Buffer[9] = (char*)"    `##``       ``###`         ## ```````````##";   
 Store.Buffer[10] = (char*)"    ###  `         ##          ##`          `##";   
 Store.Buffer[11] = (char*)"    `###`  `     ####          ## `          ##";   
 Store.Buffer[12] = (char*)"       ###########```       ` `################";   

 Store.Length = strlen("        `      ````##`                      `##");
 Store.MaxSize = 13;
 Store.Color = 15;
}

void Village::Update()
{
    dwkey = InputManager::GetInstance()->GetKey();

}

void Village::Render()
{
    for (int i = 0; i < Quest.MaxSize; ++i)
    {
        CursorManager::GetInstance()->WriteBuffer(145.0f - Quest.Length,
            5.0f + i, Quest.Buffer[i], Quest.Color);
    }
}

void Village::Release()
{
}
