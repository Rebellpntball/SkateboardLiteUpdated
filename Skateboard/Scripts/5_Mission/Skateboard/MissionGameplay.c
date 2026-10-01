modded class MissionGameplay
{
    ref SkateboardControl m_SkateboardControl;
	private Object targetObj;
	private Object parentObj;
	private PlayerBase player;


    void MissionGameplay()
    {
        m_SkateboardControl = new ref SkateboardControl();
	}

    override void OnKeyPress( int key ) //outcomment after all is finished
    {
        super.OnKeyPress( key );

        m_SkateboardControl.OnKeyPress( key );
    }
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		Input input = GetGame().GetInput();
		if (input.LocalPress("UASkateboardAheadSpeed", true))
		{
	        GetRPCManager().SendRPC( "Skateboard", "Ahead", new Param1< string >( "" ) );
        }
		else if (input.LocalPress("UASkateboardBackSpeed", true))
		{
	        GetRPCManager().SendRPC( "Skateboard", "Back", new Param1< string >( "" ) );
        }
		else if (input.LocalPress("UASkateboardRudderLeft", true))
		{
	        GetRPCManager().SendRPC( "Skateboard", "SteeringLeft", new Param1< string >( "" ) );
        }
		else if (input.LocalPress("UASkateboardRudderRight", true))
		{
	        GetRPCManager().SendRPC( "Skateboard", "SteeringRight", new Param1< string >( "" ) );
        }
		else if (input.LocalPress("UASkateboardRudderCenter", true))
		{
	        GetRPCManager().SendRPC( "Skateboard", "SteeringZero", new Param1< string >( "" ) );
        }
	}
};