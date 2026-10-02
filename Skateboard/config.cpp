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
