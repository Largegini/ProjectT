#pragma once
#include "Map.h"
class Dungeon1 : public Map
{
public:
	Dungeon1();
	virtual ~Dungeon1();
private:
	RenderInfo Intro1;
	RenderInfo Intro2;
	RenderInfo Intro3;
	RenderInfo Intro4;
	RenderInfo Intro5;
	RenderInfo Intro6;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
};
 .d88b.  db    db d88888b .d8888. d888888b      .d8888. d888888b  .d8b.  d8888b. d888888b db 
.8P  Y8. 88    88 88'     88'  YP `~~88~~'      88'  YP `~~88~~' d8' `8b 88  `8D `~~88~~' 88 
88    88 88    88 88ooooo `8bo.      88         `8bo.      88    88ooo88 88oobY'    88    YP 
88    88 88    88 88~~~~~   `Y8b.    88           `Y8b.    88    88~~~88 88`8b      88       
`8P  d8' 88b  d88 88.     db   8D    88         db   8D    88    88   88 88 `88.    88    db 
 `Y88'Y8 ~Y8888P' Y88888P `8888Y'    YP         `8888Y'    YP    YP   YP 88   YD    YP    YP 
                                                                                             
                                                                                             