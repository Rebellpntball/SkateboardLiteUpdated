modded class ModItemRegisterCallbacks
{	
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		
		pType.AddItemInHandsProfileIK("Skateboard_ruder_log", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior,		"dz/anims/anm/player/ik/gear/LongWoodenStick.anm");	
		
		pType.AddItemInHandsProfileIK("Acanthopagrus", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,							"dz/anims/anm/player/ik/gear/carp_live.anm");
		pType.AddItemInHandsProfileIK("Chub", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,							"dz/anims/anm/player/ik/gear/carp_live.anm");
		pType.AddItemInHandsProfileIK("Herring", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,							"dz/anims/anm/player/ik/gear/carp_live.anm");
		pType.AddItemInHandsProfileIK("Mulloway", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,							"dz/anims/anm/player/ik/gear/carp_live.anm");
	}
	override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterTwoHanded(pType, pBehavior);

		pType.AddItemInHandsProfileIK("Skateboard_ruder", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior,			"dz/anims/anm/player/ik/two_handed/firewood.anm");

		pType.AddItemInHandsProfileIK("Skateboard_ruder_planks", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior,							"dz/anims/anm/player/ik/two_handed/wooden_plank.anm"); 
		
		//pType.AddItemInHandsProfileIK("Skateboard_Paddle", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_fireaxe.asi", pBehavior, 				"dz/anims/anm/player/ik/two_handed/paddle.anm");
		
		pType.AddItemInHandsProfileIK("Skateboard_Packed", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_fireaxe.asi", pBehavior, 		"dz/anims/anm/player/ik/two_handed/FirefighterAxe.anm");
		//pType.AddItemInHandsProfileIK("Skateboard_Packed", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_farminghoe.asi", pBehavior, 			"dz/anims/anm/player/ik/two_handed/farming_hoe.anm");
		//"dz/anims/anm/player/ik/two_handed/farming_hoe.anm
	}
	override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy(pType, pBehavior);

		
    }
};