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
        name = "Skateboard";
        credits = "HunterCZ";
        author = "Lugge";
        authorID = "0";
        version = "1.0";
        extra = 0;
        type = "mod";
		inputs="Skateboard/Data/Inputs.xml";
		class defs
		{
			class gameScriptModule
            {
                value = "";
                files[] = {
				"Skateboard/scripts/3_Game",
				"RoadTripDefines/scripts/Common"
				};
            };	
			class worldScriptModule
			{
				value = "";
				files[] = {
				"Skateboard/Scripts/4_World",
				"RoadTripDefines/scripts/Common"
				};
			};
			class missionScriptModule
            {
                value="";
                files[]={
				"Skateboard/Scripts/5_Mission",
				"RoadTripDefines/scripts/Common"
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
	class Skateboard_NT_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_01_nt_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_01_nt_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_01_nt_co.paa"
		};
	};
	class Skateboard_01_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_01_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_01_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_01_co.paa"
		};
	};
	class Skateboard_02_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_02_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_02_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_02_co.paa"
		};
	};
	class Skateboard_03_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_03_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_03_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_03_co.paa"
		};
	};
	class Skateboard_04_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_04_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_04_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_04_co.paa"
		};
	};
	class Skateboard_05_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_05_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_05_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_05_co.paa"
		};
	};
	class Skateboard_06_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_06_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_06_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_06_co.paa"
		};
	};
	class Skateboard_07_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_07_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_07_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_07_co.paa"
		};
	};
	class Skateboard_08_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_08_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_08_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_08_co.paa"
		};
	};
	class Skateboard_09_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_09_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_09_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_09_co.paa"
		};
	};
	class Skateboard_10_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_10_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_10_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_10_co.paa"
		};
	};
	class Skateboard_11_Packed: Skateboard_Packed
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_11_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_11_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_11_co.paa"
		};
	};

	class Skateboard: CarScript
	{
		scope=0;
		displayName="Skateboard";
		descriptionShort="Skateboard";
		model="Skateboard\model\Skateboard.p3d";
		fuelCapacity=42;
		fuelConsumption=11;
		attachments[]=
		{

		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		class SimulationModule: SimulationModule
		{
			drive="DRIVE_AWD";
			airDragCoefficient=0.995;
			class Steering
			{
				increaseSpeed[]={0,45,60,23,100,12};
				decreaseSpeed[]={0,80,60,40,90,20};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=1;
				defaultThrust=0.85000002;
				gentleThrust=0.69999999;
				turboCoef=4;
				gentleCoef=0.75;
			};
			braking[] = {0.0, 0.1, 1.0, 0.8, 2.5, 0.9, 3.0, 1.0};
			class Engine
			{
				inertia=0.15000001;
				torqueMax=114;
				torqueRpm=3400;
				powerMax=53.700001;
				powerRpm=5400;
				rpmIdle=850;
				rpmMin=900;
				rpmClutch=1350;
				rpmRedline=6000;
				rpmMax=8000;
			};
			class Gearbox
			{
				reverse=3.526;
				ratios[]={3.6670001,2.0999999,1.3609999,1};
				timeToUncoupleClutch=0.30000001;
				timeToCoupleClutch=0.44999999;
				maxClutchTorque=260;
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxSteeringAngle=30;
					finalRatio=4.0999999;
					brakeBias=0.60000002;
					brakeForce=4000;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Suspension
					{
						swayBar=500;
						stiffness=10000;
						compression=2100;
						damping=12000;
						travelMaxUp=0.098200003;
						travelMaxDown=0.093300002;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_1";
							inventorySlot="NivaWheel_1_1";
						};
						class Right: Right
						{
							animDamper="damper_2_1";
							inventorySlot="NivaWheel_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxSteeringAngle=30;
					finalRatio=4.0999999;
					brakeBias=0.40000001;
					brakeForce=3800;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Suspension
					{
						swayBar=500;
						stiffness=10000;
						compression=2200;
						damping=12000;
						travelMaxUp=0.093300002;
						travelMaxDown=0.093300002;
					};
					class Wheels: Wheels
					{
						class Left: Left
						{
							animDamper="damper_1_2";
							inventorySlot="NivaWheel_1_2";
						};
						class Right: Right
						{
							animDamper="damper_2_2";
							inventorySlot="NivaWheel_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			//itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=0;
			openable=0;
		};
		class AnimationSources: AnimationSources
		{
			class SeatDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.80000001;
			};
			class SeatCoDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.80000001;
			};
			class damper_1_1
			{
				source="user";
				initPhase=0.48570001;
				animPeriod=1;
			};
			class damper_2_1: damper_1_1
			{
			};
			class damper_1_2
			{
				source="user";
				initPhase=0.40020001;
				animPeriod=1;
			};
			class damper_2_2: damper_1_2
			{
			};
			class steering_rudder
			{
				source="user";
				animPeriod=3.0099999998;
				initPhase=0;

			};
			class IndicatorRPM
			{
				source="user";
				animPeriod=2.0099999998;
				initPhase=0;

			};
			class Sail_part_1
			{
				source="user";
				animPeriod=4.0099999998;
				initPhase=0;

			};
			class updown_Main
			{
				source="user";
				animPeriod=8.0099999998;
				initPhase=0;

			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10000;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_chassis"
					};
					class Health
					{
						hitpoints=13000;
						transferToGlobalCoef=0;
					};
					inventorySlots[]={};
				};
				class Front
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_front"
					};
					componentNames[]=
					{
						"dmgZone_front"
					};
					class Health
					{
						hitpoints=11200;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\green\niva_body_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_1",
						"Fender_2_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.69999999,0.69999999,0.80000001};
					inventorySlots[]=
					{

					};
					inventorySlotsCoefs[]={0.69999999,0.5,0.80000001,0.80000001};
				};
				class Reflector_1_1
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_lights_1_1"
					};
					memoryPoints[]=
					{
						"dmgZone_lights_1_1"
					};
					class Health
					{
						hitpoints=10;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\headlights_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\glass_i_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\glass_i_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Fender_1_1"
					};
					transferToZonesCoefs[]={1,1};
					inventorySlots[]=
					{

					};
					inventorySlotsCoefs[]={1,0.89999998};
				};
				class Reflector_2_1: Reflector_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_lights_2_1"
					};
					componentNames[]=
					{
						"dmgZone_lights_2_1"
					};
					transferToZonesNames[]=
					{
						"Front",
						"Fender_2_1"
					};
					inventorySlots[]=
					{

					};
				};
				class Back
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_back"
					};
					componentNames[]=
					{
						"dmgZone_back"
					};
					class Health
					{
						hitpoints=11500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
								}
							},
							
							{
								0.69999999,
								
								{
									
								}
							},
							{
								0.5,
								
								{
								}
							},
							
							{
								0.30000001,
								
								{
								}
							},
							
							{
								0,
								
								{
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_2",
						"Fender_2_2",
						"WindowLR",
						"WindowRR"
					};
					transferToZonesCoefs[]={0.30000001,0.30000001,0.2,0.2};
					inventorySlots[]=
					{

					};
					inventorySlotsCoefs[]={0.89999998,0.89999998,0.89999998};
				};
				class Roof
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_roof"
					};
					memoryPoints[]=
					{
						"dmgZone_roof"
					};
					class Health
					{
						hitpoints=1700;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
								}
							},
							
							{
								0.69999999,
								
								{
								}
							},
							
							{
								0.5,
								
								{
								}
							},
							
							{
								0.30000001,
								
								{
								}
							},
							
							{
								0,
								
								{
								}
							}
						};
					};
					inventorySlotsCoefs[]={};
					inventorySlots[]={};
				};
				class Fender_1_1
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fender_1_1"
					};
					memoryPoints[]=
					{
						"dmgZone_fender_1_1"
					};
					class Health
					{
						hitpoints=1200;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
								}
							},
							
							{
								0.69999999,
								
								{
								}
							},
							
							{
								0.5,
								
								{
								}
							},
							
							{
								0.30000001,
								
								{
								}
							},
							
							{
								0,
								
								{
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Reflector_1_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.60000002,0.40000001};
					inventorySlots[]=
					{


					};
					inventorySlotsCoefs[]={0.60000002,0.89999998,0.30000001};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_2_1"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_1"
					};
					transferToZonesNames[]=
					{
						"Front",
						"Reflector_2_1",
						"Engine"
					};
					transferToZonesCoefs[]={0.30000001,0.60000002,0.40000001};
					inventorySlots[]=
					{

					};
					inventorySlotsCoefs[]={0.60000002,0.89999998,0.30000001};
				};
				class Fender_1_2: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_1_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_1_2"
					};
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank",
						"WindowLR"
					};
					transferToZonesCoefs[]={0.69999999,0.69999999,0.69999999};
					inventorySlots[]=
					{
	
					};
					inventorySlotsCoefs[]={0.69999999,0.89999998,0.30000001};
				};
				class Fender_2_2: Fender_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_fender_2_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_2"
					};
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank",
						"WindowRR"
					};
					transferToZonesCoefs[]={0.69999999,0.69999999,0.69999999};
					inventorySlots[]=
					{

					};
					inventorySlotsCoefs[]={0.69999999,0.89999998,0.30000001};
				};
				class WindowFront
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_windowFront"
					};
					componentNames[]=
					{
						"dmgZone_windowFront"
					};
					class Health
					{
						hitpoints=120;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
								}
							},
							
							{
								0.30000001,
								
								{
								}
							},
							
							{
								0,
								"hidden"
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class WindowLR
				{
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_windowLeft"
					};
					componentNames[]=
					{
						"dmgZone_windowLeft"
					};
					class Health
					{
						hitpoints=150;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
								}
							},
							
							{
								0.30000001,
								
								{
								}
							},
							
							{
								0,
								"hidden"
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class WindowRR: WindowLR
				{
					memoryPoints[]=
					{
						"dmgZone_windowRight"
					};
					componentNames[]=
					{
						"dmgZone_windowRight"
					};
				};
				class Engine
				{
					fatalInjuryCoef=0.001;
					memoryPoints[]=
					{
						"dmgZone_engine"
					};
					componentNames[]=
					{
						"dmgZone_engine"
					};
					class Health
					{
						hitpoints=11000;
						transferToGlobalCoef=1;
						healthLevels[]=
						{
							
							{
								1,
								
								{
								}
							},
							
							{
								0.69999999,
								
								{
								}
							},
							
							{
								0.5,
								
								{
								}
							},
							
							{
								0.30000001,
								
								{
								}
							},
							
							{
								0,
								
								{
								}
							}
						};
					};
					inventorySlots[]=
					{
						
					};
					inventorySlotsCoefs[]={0.2,0.2,0.40000001};
				};
				class FuelTank
				{
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fuelTank"
					};
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
			};
		};
		class ObstacleGenerator
		{
			carve=1;
			timeToStationary=5;
			moveThreshold=0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius=1;
						height=1.5;
						center[]={0,0,0.69999999};
					};
					class Cyl3
					{
						radius=1;
						height=1.5;
						center[]={0,0,-0.69999999};
					};
				};
			};
		};
	};
	class Skateboard_NT: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_01_nt_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_01_nt_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_01_nt_co.paa"
		};
	};
	class Skateboard_01: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_01_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_01_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_01_co.paa"
		};
	};
	class Skateboard_02: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_02_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_02_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_02_co.paa"
		};
	};
	class Skateboard_03: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_03_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_03_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_03_co.paa"
		};
	};
	class Skateboard_04: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_04_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_04_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_04_co.paa"
		};
	};
	class Skateboard_05: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_05_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_05_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_05_co.paa"
		};
	};
	class Skateboard_06: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_06_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_06_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_06_co.paa"
		};
	};
	class Skateboard_07: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_07_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_07_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_07_co.paa"
		};
	};
	class Skateboard_08: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_08_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_08_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_08_co.paa"
		};
	};
	class Skateboard_09: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_09_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_09_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_09_co.paa"
		};
	};
	class Skateboard_10: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_10_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_10_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_10_co.paa"
		};
	};
	class Skateboard_11: Skateboard
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\Skateboard\model\skateboard\data\skateboard_11_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_11_co.paa",
			"\Skateboard\model\skateboard\data\skateboard_11_co.paa"
		};
	};

};
class CfgSounds
{
	class default
	{
		name="";
		titles[]={};
	};
	class DieselSound_idle: default
	{
		sound[]=
		{
			
			1,
			1,
			200
		};
	};
};

class CfgSoundSets
{

	
	
	class windobject_SoundSet
	{
		soundShaders[]=
		{
			"windobject_SoundShader"
		};
		volumeFactor=2;
		frequencyRandomizer=3;
		spatial=1;
		doppler=0;
		loop=1;
		volumeCurve="objectInner7VolumeCurve";
		sound3DProcessingType="WaterStream3DProcessingType";
	};
	class WindObjectStrong_SoundSet
	{
		soundshaders[]=
		{
			"WindObjectStrong_SoundShader"
		};
		volumeFactor=2;
		frequencyRandomizer=3;
		spatial=1;
		doppler=0;
		loop=1;
		volumeCurve="objectInner7VolumeCurve";
		sound3DProcessingType="WaterStream3DProcessingType";
	};
};

class CfgSoundShaders
{
	class windobject_SoundShader
	{
		samples[]=
		{
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			},
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			},
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			},
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			},
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			}
		};
		volume=0.15;
		range=20;
	};
	class WindObjectStrong_SoundShader
	{
		samples[]=
		{
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			},
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			},
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			},
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			},
			
			{
				"DZ\sounds\vehicles\shared\tires\offroad_dirt_turn_EXT",
				1
			}
		};
		volume=0.05;
		range=20;
	};
};