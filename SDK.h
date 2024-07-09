#pragma once
#include "string.h"
#include "HelperFunctions.h"
#include <list>


struct Horse {
	char pad[0x18];
		bool localControl;
		char seats[0x8];
		char rig[0x8];
		char view[0x8];
		char mask[0x4];
		Vector2 movementInput;
		Vector3 lookDirection;
		float speed;
		float gravity;
		float drag;
		float sideDrag;
		float sideDragDrift;
		float velRot;
		float angularDrag;
		float upHelp;
		float forwardRot;
		float rayLength;
		char rayTrans[0x8];
		float standForce;
		char standCurve[0x8];
		bool isGrounded;
		char driftPart1[0x8];
		char driftPart2[0x8];
		char lines[0x8];
		char rings[0x8];
		char burst[0x8];
		char smallBurst[0x8];
		char smallLines[0x8];
		char horseHead[0x8];
		float currentLean;
		char anim[0x8];
		Vector3 startPos;
		int driftLevel;
		bool isEating;
		Vector3 lastRoadPos;
		float sinceRider;
		float sinceDrift;
		float speedBoost;
		int drift;
		float requestT;
		bool royalGrass;
};

struct Seat {

		struct Horse* horse;
		char seatPos[0x8];
		char occupant[0x8];
		int seatID;
};

struct Farm {
	char pad[0x18];
	int tier;
	bool playHeader;
	char col[0x8];
	bool switchMat;
	char from[0x8];
	char to[0x8];
	bool nightObjectsOn;
	bool isNight;
	char townOpensUpAction[0x8];
	char townClosesDownAction[0x8];
	char townObjects[0x8];
	char playersInTown[0x8];
	bool hasLocalPlayer;
	char townName[0x8];
};


struct PlayerData {

	char playerName[0x18];
	bool needHorse;
	float dontDoActionsFor;
	float currentSpread;
	float sinceAbilityUse;
	bool isReloading;
	float reloadingProgress;
	float currentSlow;
	int totalAmmo;
	int bulletsLoaded;
	int currentBombs;
	int jumps;
	int jumpsUsed;
	struct PlayerRefs* refs;
	float sinceJump;
	float sinceGroundedOrJumped;
	float sinceGrounded;
	char groundTransform[0x8];
	Vector3 groundNormal;
	Vector3 groundPos;
	bool isGrounded;
	bool isCrouching;
	Vector3 positionDelta;
	Vector3 lastPos;
	float groundedFor;
	float currentHealthPercentage;
	bool inFarm;
	char currentSeat[0x8];
	char currentHeldObject[0x4];
	int ColourPrimary;
	int ColourSecondary;
	int armorIndex;
	char causeOfDeath[0x4];
	bool playerActive;
	char playerRange[0x4];
	int framesCulled;
	float iceSpeedM;
	bool groundedThisFrame;
	float height;
	bool isDriver;
	float sinceDealDamage;
	bool isGhost;
	int currentBandage;
	bool isChanneling;
	bool beingChannelled;
	float channelProgress;
	float cancelChannelProgress;
	char channelActionName[0x8];
	float speedM;
	char belovedHorse[0x8];
	bool isChatting;
	char currentChatMessage[0x8];
	bool allowTK;
	bool isCharging;
	float currentCharge;
	int framesSinceCharging;
	float currentIceTime;
	char dataStrings[0x8];
	//GameObject currentPing;
};
struct PlayerStatsEntry {
	char pad[0x10];
	float baseValue;
	float multiplier;
	float defaultBaseValue;
	float defaultMultiplier;
};
struct PlayerStats {
	char pad[0x10];
	struct PlayerStatsEntry* Health;
	struct PlayerStatsEntry* LifeSteal;
	struct PlayerStatsEntry* Speed;
	struct PlayerStatsEntry* AbilityCooldown;
	struct PlayerStatsEntry* FireRate;
	struct PlayerStatsEntry* FireRateToAutoM;
	struct PlayerStatsEntry* Spread;
	struct PlayerStatsEntry* ReloadSpeed;
	struct PlayerStatsEntry* AutoReloadDelay;
	struct PlayerStatsEntry* Ammo;
	struct PlayerStatsEntry* NrOfProjectiles;
	struct PlayerStatsEntry* Damage;
	struct PlayerStatsEntry* ProjectileSpeed;
	struct PlayerStatsEntry* ProjectileSpeedMax;
	struct PlayerStatsEntry* ShootChargeUpTime;
	struct PlayerStatsEntry* ProjectileBounces;
	struct PlayerStatsEntry* BombFuseTime;
	struct PlayerStatsEntry* AmmoConsumption;
	struct PlayerStatsEntry* MinRange;
	struct PlayerStatsEntry* MaxRange;
	struct PlayerStatsEntry* MaxRangeDamageMultiplier;
};
struct Player {
	char pad1[0x18];
	struct PlayerStats* stats;
	char pad[0x20];
	struct Farm* enteredFarms;
	char pad2[0x20];
	struct PlayerData* data;
	struct PlayerRefs* refs;
};

struct Pl_Movement {
	char pad[0x18];
	struct Player* player;
	float jumpForce;
	float gravity;
	float drag;
	float airControl;
	char standCurve[0x4];
	float standForce;
	float standYDrag;
	float rayL;
	char rig[0x8];
	char input[0x8];
	char mask[0x4];
	float rot;
	float movementSpeedM;
	Vector3 lastPos;
	float slopeM;
	char rays[0x8];
	char landAction[0x8];
	char jumpAction[0x8];
};

struct PlayerRefs {

	char pad[0x30];
	struct Player* player;
	struct Pl_Movement* movement;
	/*PlayerCameraYRotation cameraRot;
	PhotonView view;
	Pl_Holding holding;
	Collider mainCollider;
	internal Pl_Riding riding;
	Transform horsePivot;
	Transform rightHand;
	internal Gun gun;
	internal Pl_Items items;
	internal SyncPlayerMovement syncing;
	internal Damagable damagable;
	internal PlayerSFXHandler soundHandler;
	internal PlayerWeaponHandler weaponHandler;
	internal Pl_Chanelling channeling;
	internal Throwing throwing;*/
};




