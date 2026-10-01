modded class DayZPlayerImplementJumpClimb
{
	static bool jumpskateboard;
	protected PlayerBase player;
	override private void Jump()
	{
		jumpskateboard = true;

		if (GetGame().IsServer())
		{

		
			Object parentobj = m_Player.GetParent();
		
			if (parentobj && parentobj.IsKindOf("Skateboard"))
			{
				Skateboard board = Skateboard.Cast( parentobj );
				float jumphight = board.GetSkateboardjump();
				jumphight = 20000;
				board.SetSkateboardjump(jumphight);
			}
        }
		super.Jump();
	}
}
