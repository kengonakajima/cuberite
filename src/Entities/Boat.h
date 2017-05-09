
// Boat.h

// Declares the cBoat class representing a boat in the world





#pragma once

#include "Entity.h"



// tolua_begin

class cBoat :
	public cEntity
{
	typedef cEntity super;

public:
	// tolua_end

	CLASS_PROTODEF(cBoat)

	// cEntity overrides:
	virtual void SpawnOn(cClientHandle & a_ClientHandle) override;
	virtual void OnRightClicked(cPlayer & a_Player) override;
	virtual bool DoTakeDamage(TakeDamageInfo & TDI) override;
	virtual void Tick(std::chrono::milliseconds a_Dt, cChunk & a_Chunk) override;
	virtual void HandleSpeedFromAttachee(float a_Forward, float a_Sideways) override;

	/** The type is the wood type of the boat. There are five boat types (0 = oak, 1 = spruce, 2 = birch, 3 = jungle, 4 = acacia, 5 = dark oak) */
	cBoat(double a_X, double a_Y, double a_Z, eBoatType a_BoatType = btOak);

	int GetLastDamage(void) const { return m_LastDamage; }
	int GetForwardDirection(void) const { return m_ForwardDirection; }

	float GetDamageTaken(void) const { return m_DamageTaken; }

	int GetType(void) const { return m_Type; }  // tolua_export

	bool IsRightPaddleUsed(void) const { return m_RightPaddleUsed; }
	bool IsLeftPaddleUsed(void) const { return m_LeftPaddleUsed; }

	void SetLastDamage(int TimeSinceLastHit);

	void UpdatePaddles(bool rightPaddleUsed, bool leftPaddleUsed);

private:
	int m_LastDamage;
	int m_ForwardDirection;

	float m_DamageTaken;

	int m_Type;

	bool m_RightPaddleUsed;
	bool m_LeftPaddleUsed;
} ;  // tolua_export
