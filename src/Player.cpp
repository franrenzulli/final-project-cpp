#include "Player.h"

Player::Player(bool player_one) : Object(player_one?"../assets/images/rambo.png":"../assets/images/rambo.png") {
	if(player_one){
		m_sprite.setPosition(20,200);
	}else{
		m_sprite.setPosition(600,200);
	}
}

void Player::Update(){
	
}
