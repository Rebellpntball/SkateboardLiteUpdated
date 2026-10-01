class SkateboardControl //finish
{
	protected static ref SkateboardControl Instance;
	protected PlayerBase player;
	
	void SkateboardControl()
    {
		GetRPCManager().AddRPC( "Skateboard", "Ahead", this, SingeplayerExecutionType.Client );
		GetRPCManager().AddRPC( "Skateboard", "Back", this, SingeplayerExecutionType.Client );
		GetRPCManager().AddRPC( "Skateboard", "SteeringRight", this, SingeplayerExecutionType.Client );
		GetRPCManager().AddRPC( "Skateboard", "SteeringLeft", this, SingeplayerExecutionType.Client );
		GetRPCManager().AddRPC( "Skateboard", "SteeringZero", this, SingeplayerExecutionType.Client );
    }
	static SkateboardControl GetInstance()
	{
		if (!Instance)
        {
            Instance = new SkateboardControl();
        }
		return Instance;
	}
	static void ClearInstance()
	{
		Instance = null;
	}
	void Ahead( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) //Move Forward
    {
        Param1< string > data;
        if ( !ctx.Read( data ) ) return; 
        if( type == CallType.Server )
        {
			player = GetPlayerByPlainID(sender.GetPlainId());
			Object parentobj = player.GetParent();
			if (parentobj && parentobj.IsKindOf("Skateboard"))
			{
				Skateboard lodka = Skateboard.Cast( parentobj );
				int speed = lodka.GetSkateboardSpeed();
				speed++;
				speed = Math.Clamp(speed,-1,2);
				lodka.SetSpeed(speed);
			}
        }
    }
	void Back(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) //Move Back
    {
        Param1< string > data;
        if ( !ctx.Read( data ) ) return;
        if( type == CallType.Server )
        {
			player = GetPlayerByPlainID(sender.GetPlainId());
			Object parentobj = player.GetParent();
			if (parentobj && parentobj.IsKindOf("Skateboard"))
			{
				Skateboard lodka = Skateboard.Cast( parentobj );
				int speed = lodka.GetSkateboardSpeed();
				speed--;
				speed = Math.Clamp(speed,-1,2);
				lodka.SetSpeed(speed);
			}
        }
    }
	
	void SteeringRight( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) //right
    {
        Param1< string > data;
        if ( !ctx.Read( data ) ) return;
        if( type == CallType.Server )
        {
			player = GetPlayerByPlainID(sender.GetPlainId());
			Object parentobj = player.GetParent();
			if (parentobj && parentobj.IsKindOf("Skateboard"))
			{
				Skateboard lodka = Skateboard.Cast( parentobj );
				float angle = lodka.GetSkateboardRudderAngle();
				angle -= 10.85;
				angle = Math.Clamp(angle,-45,45);
				lodka.SetSkateboardRudderAngle(angle);
			}
        }
    }
	
	void SteeringLeft( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) //left
    {
        Param1< string > data;
        if ( !ctx.Read( data ) ) return;
        if( type == CallType.Server )
        {
			player = GetPlayerByPlainID(sender.GetPlainId());
			//player = PlayerBase.Cast(sender);
			Object parentobj = player.GetParent();
			if (parentobj && parentobj.IsKindOf("Skateboard"))
			{
				Skateboard lodka = Skateboard.Cast( parentobj );
				float angle = lodka.GetSkateboardRudderAngle();
				angle += 10.85;
				angle = Math.Clamp(angle,-45,45);
				lodka.SetSkateboardRudderAngle(angle);
			}
        }
    }
	
	void SteeringZero( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) //angular 0
    {
        Param1< string > data;
        if ( !ctx.Read( data ) ) return;
        if( type == CallType.Server )
        {
			player = GetPlayerByPlainID(sender.GetPlainId());
			Object parentobj = player.GetParent();
			if (parentobj && parentobj.IsKindOf("Skateboard"))
			{
				Skateboard lodka = Skateboard.Cast( parentobj );
				float angle = lodka.GetSkateboardRudderAngle();
				angle = 0;
				angle = Math.Clamp(angle,-45,45);
				lodka.SetSkateboardRudderAngle(angle);
			}
        }
    }		
	protected static PlayerBase GetPlayerByPlainID(string plainID)
	{
		array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);
		for(int i = 0; i < players.Count(); i++)
		{
			if(players.Get(i).GetIdentity().GetPlainId() == plainID)
			{
				return PlayerBase.Cast(players.Get(i));
			}
		}
		return null;
	}
    void OnKeyPress( int key )
    {

    }
};