class Skateboard_Packed extends DeployableContainer_Base
{
    void Skateboard_Packed()
    {
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
        RegisterNetSyncVariableBool("m_IsPlaceSound");
    }   
    override int GetDamageSystemVersionChange()
    {
        return 110;
    }
    override bool CanPutInCargo( EntityAI parent )
    {
        return true;
    }
	override bool IsBasebuildingKit() //delets Skateboard packed
    {
        return true;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        return true;
    }
    override bool CanReceiveItemIntoCargo( EntityAI item )
    {  
        return true;
    }
    override bool CanReleaseCargo( EntityAI attachment )
    {
        return true;
    }
	override bool IsHeavyBehaviour()
    {
        return false;
    }
	override bool IsTwoHandedBehaviour()
	{
		return false;
	} 
	string getpackedname()
	{
		return "Skateboard_NT";
	}
    override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
    {
        super.OnPlacementComplete(player, position, orientation);
        if (GetGame().IsServer())
        {
            EntityAI Skateboardplace = EntityAI.Cast(GetGame().CreateObjectEx(getpackedname(), position, ECE_PLACE_ON_SURFACE));
            Skateboardplace.SetPosition(position);
            Skateboardplace.SetOrientation(orientation);
        }

        SetIsDeploySound(true);
    }

    override void SetActions()
    {
		super.SetActions();
	 	//AddAction(ActionPlaceObject);
        AddAction(ActionTogglePlaceObject);
        AddAction(ActionDeployObject);
    }
};
class Skateboard_NT_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_NT";
	}
}

class Skateboard_01_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_01";
	}
}
class Skateboard_02_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_02";
	}
}
class Skateboard_03_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_03";
	}
}
class Skateboard_04_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_04";
	}
}
class Skateboard_05_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_05";
	}
}
class Skateboard_06_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_06";
	}
}
class Skateboard_07_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_07";
	}
}
class Skateboard_08_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_08";
	}
}
class Skateboard_09_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_09";
	}
}
class Skateboard_10_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_10";
	}
}
class Skateboard_11_Packed extends Skateboard_Packed
{
	override string getpackedname()
	{
		return "Skateboard_11";
	}
}
