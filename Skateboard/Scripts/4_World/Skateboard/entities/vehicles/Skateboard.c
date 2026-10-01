class Skateboard extends CarScript
{	
	protected float m_TimeSlice;
	protected float m_RudderAngle;
	protected float m_Radius;
	protected vector m_Location;
	protected int m_Speed;
	//sound
	ref Timer 					m_SoundStartTimer;
	protected EffectSound 		m_EngineStart;
	protected EffectSound 		m_EngineStart_Strong;
	static const string			START_SOUND = "windobject_SoundSet";
	//CivilianSedan_dirt_turn_SoundShader
	static const string			START_SOUND_STRONG = "WindObjectStrong_SoundSet";

	protected ref EffectSound m_DieselSound;
	vector m_SteeringWheelPos;
	private Object house1;
	protected Human m_Captain;
	float pushup = 0;
	float mybyovalue;
	vector getspeed;
	bool smalerthanfour = false;
	bool halffull = false;
	bool notfull = false;
	bool full = false;
	bool soundstrong = false;
	bool soundlow = false;
	bool lockfishingrod = false;
	bool lockfishingrodFromMackerel = false;
	bool fishingrodattached = false;
	int count = 0;
	static float paddlemultiplyer = 1;
	protected float Skateboardjump;
	
	protected float Skateboard_multi = 1;
	DayZPlayerImplementJumpClimb  m_myboardjumpclass;

	
	void Skateboard()
	{
		//GetHierarchyParent(); test for fire
		m_dmgContactCoef = 0.075;

		SetEventMask( EntityEvent.CONTACT | EntityEvent.SIMULATE | EntityEvent.POSTSIMULATE | EntityEvent.POSTFRAME );
		RegisterNetSyncVariableInt("m_Speed");
		RegisterNetSyncVariableFloat("m_RudderAngle");	
		RegisterNetSyncVariableFloat("Skateboardjump");	
		if ( MemoryPointExists("steering_wheel_wood_axis") )
			m_SteeringWheelPos = GetMemoryPointPos("steering_wheel_wood_axis");
		else
			m_SteeringWheelPos = "0 0 0";		
	}
	void ~Skateboard()
	{
		
		soundlow = false;
		soundstrong = false;
		StopSoundSet(m_EngineStart);
		StopSoundSet(m_EngineStart_Strong);
	}
	string getpackedname()
	{
		return "null";
	}
	protected float Skateboard_SpeedmultiPos = 1;
	
	void setSkateboardSpeedmulti(float multi) {
		//Print("Ausführen von Skateboard");
		Skateboard_SpeedmultiPos = multi;
	}
	
	bool CheckForPlayers()
	{
		
		//Print("Geht los der Check");
		vector Skateboard_Pos = this.ModelToWorld(this.m_SteeringWheelPos);
		auto objects = new array<Object>;
		auto proxyCargos = new array<CargoBase>;
		float Skateboard_multi = 1.0;
		bool Skateboard_player_found = false;
		
		GetGame().GetObjectsAtPosition3D( Skateboard_Pos, 3, objects, proxyCargos );

		if (objects)
		{
			foreach(Object obj : objects) 
			{
				//Print("Hier ist ein OBJ");
				if (obj.IsMan()) 
				{
					//Print("Jo Player gefunden");
					Skateboard_player_found = true;
						
					Skateboard_multi = 1.0;
						
					

				}
			}
		}
		if (Skateboard_player_found)
		{
			setSkateboardSpeedmulti(Skateboard_multi);
			return true;
		}
		else
		{
			return false;
		}
		
	}
	
	override void EOnSimulate( IEntity owner, float dt ) 
	{
		if ( GetGame().IsServer() || !GetGame().IsMultiplayer() )
 		{
			UpdatePhysics( dt );
			

		}	
	}

	
	void InitSound()
	{
		soundstrong = true;
		if (!m_SoundStartTimer)
			m_SoundStartTimer = new Timer( CALL_CATEGORY_SYSTEM );
		
		if (!m_SoundStartTimer.IsRunning() && soundstrong) 
		{
			PlaySoundSetLoop( m_EngineStart, START_SOUND, 0, 0 );
			m_SoundStartTimer.Run(4.5, this, "StartLoopSound", NULL, false);
		}
		if (!m_SoundStartTimer.IsRunning() && soundlow) 
		{
			PlaySoundSetLoop( m_EngineStart_Strong, START_SOUND_STRONG, 0, 0 );
			m_SoundStartTimer.Run(4.5, this, "StartLoopSound", NULL, false);	
		}
	}
	
	void StartLoopSound()
	{
		notfull = false;
		soundlow = false;
		soundstrong = false;
		StopSoundSet(m_EngineStart);
		StopSoundSet(m_EngineStart_Strong);
		
	}
	void SetSpeed(int speed) //Speed of Skateboard  set in SkateboardControl.c
	{
		m_Speed = speed;
		SetSynchDirty();
	}
	int GetSkateboardSpeed()
	{
		return m_Speed;
	}

	void SetSkateboardRudderAngle(float angle) //turning
	{
		m_RudderAngle = angle; // angle can be -45 to +45 set in SkateboardControl.c
		SetSynchDirty();
	}
	float GetSkateboardRudderAngle()
	{
		return m_RudderAngle;
	}
	
	void SetSkateboardjump(float jumphight) //turning
	{
		Skateboardjump = jumphight; // angle can be -45 to +45 set in SkateboardControl.c
		SetSynchDirty();
	}
	float GetSkateboardjump()
	{
		return Skateboardjump;
	}
	
	
	static void DisablePhysics(Object ent)
	{
		SetVelocity( ent, Vector( 0, 0, 0 ) );
		dBodySetAngularVelocity( ent, Vector( 0, 0, 0 ) );
		dBodyActive( ent, ActiveState.INACTIVE );
		dBodyDynamic( ent, false );
	}

	static void EnablePhysics(Object ent)
	{
		SetVelocity( ent, Vector( 0, 0, 0 ) );
	
		dBodySetAngularVelocity( ent, Vector( 0, 0, 0 ) );
		dBodyActive( ent, ActiveState.ALWAYS_ACTIVE );
		dBodyDynamic( ent, true );
	}
	Human GetCaptain() // need rewright
	{
		array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);
		for(int i = 0; i < players.Count(); i++)
		{
			if( vector.Distance( players.Get(i).GetPosition(), this.ModelToWorld(this.m_SteeringWheelPos) ) < 1 )
			{
				return PlayerBase.Cast(players.Get(i));
			}
		}
		return null;
	}	
	
	override void OnStoreSave(ParamsWriteContext ctx) 	
	{ 		
		super.OnStoreSave( ctx );
	};
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version) 	
	{
  		if ( !super.OnStoreLoad(ctx, version) )
 		{
 			return false;
		};
		SetSynchDirty();
		return true; 	
	};

	override void EOnInit( IEntity other, int extra )
	{
		/*DisablePhysics( this );
		float m_Offset = 0;
		vector position = GetPosition();
	
		if ( g_Game.SurfaceIsSea( position[0], position[2] ) )
		{
			position[1] = g_Game.SurfaceGetSeaLevel() + m_Offset;
			SetPosition( position );
		} else if ( g_Game.SurfaceIsPond( position[0], position[2] ) )
		{
			float depth = g_Game.GetWaterDepth( position ) + m_Offset;
			position[1] = position[1] + depth;
			SetPosition( position );
		}

		SetOrientation( "0 0 0" );

		EnablePhysics( this );*/
	}
	
	override void EOnContact( IEntity other, Contact extra ) 
    {		
		if ( GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{			
			float linVelocity = GetVelocity( this ).Length();
			
			float angVelocity = dBodyGetAngularVelocity( this ).Length();
			if ( linVelocity > 10 || angVelocity > 5 || extra.Impulse > 100000 )
			{
				//m_Damaged = true; what happens with Skateboard when Skateboard contacts with something
			}			
		}
	}
		override void SetActions()
	{
		super.SetActions();
		
        AddAction(ActionDismantleSkateboard);
	}
	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		super.EOnPostSimulate(other, timeSlice);
		UpdateSkateboardAnimations();
		
		int hour, minute, second;
		GetHourMinuteSecond(hour, minute, second);
		
		if(second % 5 == 0) {
			if(!CheckForPlayers()) {
				m_Speed = 0;
				SetSynchDirty();
			}
		}
		
		
	}
	void PlaySound()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer()) //weird sound switches that i hacked^^
		{
			
			InitSound();
				
		}
	}
	void UpdateSkateboardAnimations()
	{
		


		switch (m_Speed)
		{
			case 1:
				float tempfloat = 1.0;
				float tempfloatstop = 0.0;
				PlaySound();
				SetAnimationPhase( "Wheel01", tempfloat );
				SetAnimationPhase( "Wheel02", tempfloat );
				SetAnimationPhase( "Wheel03", tempfloat );
				SetAnimationPhase( "Wheel04", tempfloat );
			break;
			case 2:
				SetAnimationPhase( "Wheel01", tempfloat );
				SetAnimationPhase( "Wheel02", tempfloat );
				SetAnimationPhase( "Wheel03", tempfloat );
				SetAnimationPhase( "Wheel04", tempfloat );
				PlaySound();
			break;
			case 0:


				SetAnimationPhase( "Wheel01", tempfloatstop );
				SetAnimationPhase( "Wheel02", tempfloatstop );
				SetAnimationPhase( "Wheel03", tempfloatstop );
				SetAnimationPhase( "Wheel04", tempfloatstop );
			break;
			case -1:


				SetAnimationPhase( "Wheel01", tempfloat );
				SetAnimationPhase( "Wheel02", tempfloat );
				SetAnimationPhase( "Wheel03", tempfloat );
				SetAnimationPhase( "Wheel04", tempfloat );
				PlaySound();
			break;
			case -2:

				SetAnimationPhase( "Wheel01", tempfloat );
				SetAnimationPhase( "Wheel02", tempfloat );
				SetAnimationPhase( "Wheel03", tempfloat );
				SetAnimationPhase( "Wheel04", tempfloat );
				PlaySound();
			break;
		}
	}
	
	override vector GetEnginePosWS()
    {
        //HOTFIX because looks like its not loaded from model correct
        //This prevent engine damage after server restart
        return ModelToWorld( "0 20 0".ToVector() );
    }	
	bool jumptime()
	{
		count = 0;
		return true;
		

	}
	void UpdatePhysics( float dt )
	{
		float turnAmount = 0.0;
		float speedAmount = 0.0;
		float rudermuliplyer = m_RudderAngle;
		float Skateboard_speed_multiplyer = 3;
		float curvemultiplyer = 1.0;
		vector transform[4];
		vector linImpulseWS;
		vector angImpulseWS;
		vector linSpeedImpulseWS;
		vector linSpeedImpulseWS_nothrust;
		vector linImpulseMS;
		vector linSpeedImpulseMS = Vector( 0, 0, 0 );
		vector linSpeedImpulseMS_nothrust = Vector( 0, -500, 0 );
		vector angImpulseMS;
		vector impulse;
		vector thrust;
		vector up = Vector(0,1,0);
		
		float bremswiederstand;
		this.GetTransform( transform );
		float surfacedistance;
		vector posx;

		posx = this.GetPosition();
		vector posboardy;
		posboardy = this.GetPosition();
		surfacedistance = GetGame().SurfaceY(posx[0],posx[2]);
		
		Print(surfacedistance);
		Print("y");
		Print(posboardy);
		linImpulseWS = vector.Zero;
		angImpulseWS = vector.Zero;
		
	

		turnAmount = m_RudderAngle*0.15;  // 0,01575 = +45*0.00035 |||  -0,01575 = -45*0.00035
		speedAmount = m_Speed / 150; // 0,0133 = 2 / 150
		
		
		//---turn------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		impulse = Vector( -4, 0, 0 ) * Math.Lerp( dBodyGetMass( this ) * -turnAmount * speedAmount * 1 , dBodyGetMass( this ) * -turnAmount * speedAmount * 20 * 1.2 ,dt);
		angImpulseMS[1] = angImpulseMS[1] + impulse[0] * -1;
		
		//---speed-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if ((Math.Sqrt(rudermuliplyer * rudermuliplyer)) >= 30)
		{
			curvemultiplyer =  0.7;
			
		} else 
			curvemultiplyer = 1.0;
		//if (this.getposition() <= transform;

		thrust[2] = 15 * dBodyGetMass( this ) * speedAmount * Skateboard_speed_multiplyer * dt * 23 * Skateboard_multi * curvemultiplyer;

		if (posboardy[1] - 0.2 <= surfacedistance)
		{
			thrust[1] = GetSkateboardjump();
		}
			
		
		SetSkateboardjump(0);
		/*
		Skateboardjump = m_myboardjumpclass.jumpskateboard;
		if (Skateboardjump == true)
		{
			
			Print("test");
			m_myboardjumpclass.jumpskateboard = false;
			
			thrust[1] = 200000;
		}
		*/
		//thrust[1]= 100;
		linSpeedImpulseMS += thrust;

		getspeed = thrust;
		
		// jump funtion.
		//if g_Game.GetPlayer.

		
			
		

		//---upforce----------------------------------------------------------------------------------------------------------------------------------------------------------------------		
		//impulse = Vector( 0, mybyovalue, 0 ) * dBodyGetMass( this ) * dt * 2;
		//linImpulseMS += impulse;
		
		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
		//turn    (turn,0,0)
		angImpulseWS = angImpulseMS.Multiply3( transform );

		dBodyApplyTorqueImpulse( this, angImpulseWS );
		//speed   (0,0,speed)
		linSpeedImpulseWS = linSpeedImpulseMS.Multiply3( transform );
		linSpeedImpulseWS_nothrust = linSpeedImpulseMS_nothrust.Multiply3( transform );

		//dBodyApplyImpulseAt( this, linSpeedImpulseWS_nothrust, this.GetOrigin() - Vector(1,0,1));
		//dBodyApplyImpulseAt( this, linSpeedImpulseWS_nothrust, this.GetOrigin() - Vector(-1,0,-1));
		dBodyApplyImpulseAt( this, linSpeedImpulseWS, this.GetOrigin() - Vector(0,0,0));

		//upforce (0,upforce,0)
		//linImpulseWS = linImpulseMS.Multiply3( transform );
		//dBodyApplyImpulse( this, linImpulseWS );
		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if (rudermuliplyer == 0)
			bremswiederstand = 0.99;
		else
			bremswiederstand = 0.99;
			
		//lose speed
		dBodySetDamping( this, 0.4, bremswiederstand );
	}
};
class Skateboard_NT extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_NT_Packed";
	}
}
class Skateboard_01 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_01_Packed";
	}
}
class Skateboard_02 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_02_Packed";
	}
}
class Skateboard_03 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_03_Packed";
	}
}
class Skateboard_04 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_04_Packed";
	}
}
class Skateboard_05 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_05_Packed";
	}
}
class Skateboard_06 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_06_Packed";
	}
}
class Skateboard_07 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_07_Packed";
	}
}
class Skateboard_08 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_08_Packed";
	}
}
class Skateboard_09 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_09_Packed";
	}
}
class Skateboard_10 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_10_Packed";
	}
}	

class Skateboard_11 extends Skateboard
{
	string getpackedname()
	{
		return "Skateboard_11_Packed";
	}
}	

