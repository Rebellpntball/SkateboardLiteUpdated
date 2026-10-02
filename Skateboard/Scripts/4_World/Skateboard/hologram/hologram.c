// Standalone Expansion-safe Hologram patch for SkateboardLite
// Only affects Skateboard_Packed kits. Always calls super so Expansion / other
// basebuilding mods keep their full collision & projection chain.

modded class Hologram
{
	override string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());

		if (item_in_hands && item_in_hands.IsInherited(Skateboard_Packed))
			return "Skateboard";

		return super.ProjectionBasedOnParent();
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());

		// Force no-collision only for our own packed board so it can be placed
		// freely, then always run the rest of the (vanilla / Expansion) logic.
		if (item_in_hands && item_in_hands.IsInherited(Skateboard_Packed))
		{
			SetIsColliding(false);
		}

		super.EvaluateCollision(action_item);
	}
};
