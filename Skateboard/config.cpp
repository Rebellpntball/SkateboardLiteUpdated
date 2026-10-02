class CfgPatches
{
	class Skateboard
	{
		units[]= {};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Vehicles_Wheeled",
			"DZ_Characters",
			"DZ_Data",
			"DZ_Scripts",
			"JM_CF_Scripts",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Pants",
			"DZ_Characters_Tops",
			"DZ_Gear_Containers",
			"DZ_Gear_Food",
			"DZ_Characters_Headgear"
		};
	};
};

class CfgMods			
{
	class Skateboard
	{
        dir = "Skateboard";
        picture = "";
        action = "";
        hideName = 0;
        hidePicture = 0;
        name = "SkateboardLite Updated";
        credits = "Original: Lugge / HunterCZ | Update: community maintenance";
        author = "Lugge (original) + community";
        authorID = "0";
        version = "1.1";
        extra = 0;
        type = "mod";
		inputs="Skateboard/Data/Inputs.xml";
		class defs
		{
			class gameScriptModule
            {
                value = "";
                files[] = {
				"Skateboard/scripts/3_Game"
				};
            };	
			class worldScriptModule
			{
				value = "";
				files[] = {
				"Skateboard/Scripts/4_World"
				};
			};
			class missionScriptModule
            {
                value="";
                files[]={
				"Skateboard/Scripts/5_Mission"
				};
            };
		};
    };
};


class CfgVehicles
{
	class Container_Base;
	class ItemCompass;
	class Inventory_Base;
	class SimulationModule;
	class Axles;
	class Front;
	class Wheels;
	class Rear;
	class Left;
	class Right;
	class AnimationSources;
	class Crew;
	class Driver;
	class CoDriver;
	class GUIInventoryAttachmentsProps;
	class Body;
	class DamageSystem;
	class DamageZones;
	class GlobalHealth;
	class CarScript;
	
	class Skateboard_Packed: Inventory_Base
	{
		scope = 0;
		displayName = "Skateboard Packed";
		descriptionShort = "Skateboard Packed";
		model = "Skateboard\model\Skateboard_Packed.p3d";
		rotationFlags = 8;
		weight=5500;
		itemSize[]={2,8};
		fragility=0.0080000004;
		itemBehaviour=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		inventorySlot[]=
		{
			"Shoulder",
			"Melee"
		};
		suicideAnim="pitchfork";
		build_action_type=4;
		dismantle_action_type=4;
		openItemSpillRange[]={30,60};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
