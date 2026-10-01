modded class DayZPlayerImplement //disable dmg form Skateboard
{
   	override void RegisterTransportHit(Transport transport)
	{
		Skateboard skateboard = Skateboard.Cast(transport);
 		if ( Skateboard )
        {
            if ( GetGame().IsServer() || !GetGame().IsMultiplayer() )
            {
               return; 
            }
        }
		
		
		super.RegisterTransportHit(transport);
	}
}