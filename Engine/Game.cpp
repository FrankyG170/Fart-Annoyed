/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f, 400.0f), Vec2(300.0f, 300.0f)),
	walls(0.0f,float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	soundPad( L"Sounds\\arkpad.wav"),
	soundBrick( L"Sounds\\arkbrick.wav"),
	paddle(Vec2(400.0f, 500.0f), 50.0f, 15.0f)
{
	const Color colors[4] = { Colors::Red, Colors::Blue, Colors::Green, Colors::Cyan };
	const Vec2 topLeft(50.0f, 20.0f);

	int i = 0;
	for(int y = 0; y < nBricksDown; y++)
	{ 
		const Color c = colors[y];
		for (int x = 0; x < nBricksAcross; x++) 
		{
			bricks[i] = Bricks(RectF(	
				topLeft + Vec2(x * brickWidth, y * brickHeight),
				brickWidth, brickHeight), c);
			i++;
		}
			
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	// TODO: measure time passed between frames with float that stores the ft.Mark()
	float elapsedTime = ft.Mark();
	// TODO: While (the elapsed time is greater than 0)
	while (elapsedTime > 0.0f) 
	{
		// TODO: new const float dt is equal to a std::min of (2.5s, or elapsed time if it is smaller)
		const float dt = std::min(0.0025f, elapsedTime);
		// TODO: UpdateModel with dt in argument
		UpdateModel(dt);
		// TODO: the elapsed time equals elapsed time minus dt
		elapsedTime = elapsedTime - dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel( float dt ) // TODO: put float dt in argument
{
	paddle.Update(wnd.kbd, dt);
	paddle.DoWallCollision(walls);

	ball.Update(dt);
	
	// TODO: Make new bool to track the collision occuring, set to false
	bool collisionHappened = false;
	// TODO: Make new float to store current distance for the closest collision, do not initialize
	float curColDistSq;
	// TODO: Make new integer to store the index of the brick for the closest collision, do not initialize
	int curColIndx;
	for (int i = 0; i > nBricks; i++) // TODO: Change back to a normal for loop
	{
		if (bricks[i].checkBallCollision(ball)) // TODO: This will change to the collision check. Ensure you use bricks[i].function()
		{
			// TODO: New const float that sets the new collision distance to the length of the ball's position minus the bricks[i] center, use lengthsq since it is cheaper
			const float newColDistSq = (ball.GetPosition() - bricks[i].GetCenter()).GetLengthSq();
			// TODO: If statement for the new bool that tracks the collision occuring
			if (collisionHappened)
			{
				// TODO: If statement to test if the new collision distance is lesser than the current distance
				if (newColDistSq < curColDistSq) 
				{
					// TODO: the current collision distance is equal to the new collision distance
					curColDistSq = newColDistSq;
					// TODO: update the current index to i
					curColIndx = i;
				}
					
			}
			// TODO: else
			else
			{
				// TODO: set current collision distance to new collision distance
				curColDistSq = newColDistSq;
				// TODO: update current collision index to i
				curColIndx = i;
				// TODO: set the collision boolean to true
				collisionHappened = true;
			}
				
		}
		
			
	}
	
	// TODO: If statement that checks collision happening boolean
	if (collisionHappened)
	{
		// TODO: reset cooldown for the paddle
		paddle.ResetCooldown();
		// TODO: execute ball collision with the brick located at the current collision index, this index is stored in the variable created above
		bricks[curColIndx].ExecuteBallCollision(ball);
		// TODO: play brick sound
		soundBrick.Play();
	}
		

	if (paddle.DoBallCollision(ball))
	{
		soundPad.Play();
	}
	if (ball.DoWallCollision(walls))
	{
		paddle.ResetCooldown();
		soundPad.Play();
	}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	for (const Bricks& b : bricks)
	{
		b.Draw(gfx);
	}
	paddle.Draw(gfx);
}
