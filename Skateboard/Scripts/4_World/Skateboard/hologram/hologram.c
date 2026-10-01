modded class Hologram
{
	override string ProjectionBasedOnParent() //projection
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());	
		
		if (item_in_hands.IsInherited(Skateboard_Packed))
			return "Skateboard";
		return super.ProjectionBasedOnParent();
	}



    override void EvaluateCollision(ItemBase action_item = null) // remove all collition
    {
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if (item_in_hands && item_in_hands.IsInherited(Skateboard_Packed))
        {
			SetIsColliding(false);
			return;
		}
	    super.EvaluateCollision();
    }	
};
   