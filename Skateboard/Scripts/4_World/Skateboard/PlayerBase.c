/*enum M_RPCserver //Roadtip integrated 
{
	SyncSkateboardControl 
}*/

modded class PlayerBase 
{
	bool isLinked;
	bool shouldLink;
	int unlinkAttemps;
	Object linkParent;
	ActionDismantleSkateboard myActiondismant;
	float m_SkateLinkCheckTimer;		// standalone lag fix – throttle raycasts

	

	
	override bool IsInVehicle()
    {
        if (isLinked)
        {
            return false;
        }
        return super.IsInVehicle();
    }
	void LinkPlayer(Object obj) 
	{
		vector tmPlayer[4]; 
		vector tmTarget[4];
		vector tmLocal[4];
		GetTransform( tmPlayer );
		obj.GetTransform( tmTarget );
		Math3D.MatrixInvMultiply4( tmTarget, tmPlayer, tmLocal );
		LinkToLocalSpaceOf( obj, tmLocal );
		isLinked = true;
		//GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", "LinkPlayer", ""));
	}
	void UnlinkPlayer() 
	{
		UnlinkFromLocalSpace();
		//GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", "UNLinkPlayer", ""));
		isLinked = false;
	}
	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		AddAction(ActionDismantleSkateboard, InputActionMap);
	}
	override bool ModCommandHandlerBefore(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished) 
	{
		// Standalone – no RoadTrip dependency
		// Throttle expensive raycasts (~8 Hz) instead of every frame
		if (GetGame().IsClient())
		{
			m_SkateLinkCheckTimer += pDt;
			if (m_SkateLinkCheckTimer >= 0.12)
			{
				m_SkateLinkCheckTimer = 0;
				Object obj;
				ScriptInputUserData ctx;
				shouldLink = NeedLink(obj);

				if (shouldLink)
				{
					if (!isLinked && obj)
					{
						ctx = new ScriptInputUserData;
						ctx.Write(LINKTOLOCALSPACE_LINK_Skateboard);
						ctx.Write(obj);
						ctx.Send();
						ctx.Reset();
						LinkPlayer(obj);
					}
				} 
				else
				{
					if (isLinked)
					{
						ctx = new ScriptInputUserData;
						ctx.Write(LINKTOLOCALSPACE_UNLINK_Skateboard);
						ctx.Send();
						ctx.Reset();
						UnlinkPlayer();
					}
				}
			}
		}
		return super.ModCommandHandlerBefore(pDt, pCurrentCommandID, pCurrentCommandFinished);
	}
	override bool OnInputUserDataProcess(int userDataType, ParamsReadContext ctx)
	{
		if( super.OnInputUserDataProcess(userDataType, ctx) )
			return true;
		if (userDataType == LINKTOLOCALSPACE_LINK_Skateboard)
		{
			EntityAI target = null;
			if (ctx.Read(target))
			{
				LinkPlayer(target);
			}
			return true;
		} else if (userDataType == LINKTOLOCALSPACE_UNLINK_Skateboard)
		{
			UnlinkPlayer();
		}
		return false;
	}
		
	bool NeedLink(out Object object)
	{
		
		object = null;
		set<Object> objects = new set<Object>;
		vector from = GetPosition() + "0 0.3 0";  
		vector to = from - "0 1 0";

		vector contact_pos;
		vector contact_dir;

		int contact_component;
		Transport vehicle;
		array<ref RaycastRVResult> hit_proxy_objects = new array<ref RaycastRVResult>;		
		RaycastRVParams ray_input = new RaycastRVParams( from, to, this, 0.025 );
        
		DayZPhysics.RaycastRVProxy( ray_input, hit_proxy_objects );
		
		Skateboard ship;
		bool boo = DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, objects, this, this, false, false, ObjIntersectView, 0.15 );
		
		
		if (hit_proxy_objects != null)
		{
			if (hit_proxy_objects.Count() > 0)
			{
				if (hit_proxy_objects[0].parent != NULL)
				{
					Object veh = hit_proxy_objects[0].parent;
					if (veh.IsKindOf("Skateboard") && !ActionDismantleSkateboard.DismantleStopLinking)
					{						
						object = veh;
						return (true && object);
					}	
				}
			}
		}
		auto objs = GetObjectsAt( from, to, this, 0.025 );

	    if ( objs != null && objs.Count() > 0 )
		{
			if (Class.CastTo(ship, objs[0]) && !ActionDismantleSkateboard.DismantleStopLinking)
			{
				object = objs[0];
				return (true && object);
			}
		}	        
	    return (false && null);
		
	}
	set< Object > GetObjectsAt( vector from, vector to, Object ignore = NULL, float radius = 0.6, Object with = NULL )
	{
	    vector contact_pos;
	    vector contact_dir;
	    int contact_component;
	    set< Object > geom = new set< Object >;
	    set< Object > view = new set< Object >;
	    DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, geom, with, this, false, false, ObjIntersectGeom, radius, CollisionFlags.ALLOBJECTS );
	    DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, view, with, this, false, false, ObjIntersectView, radius, CollisionFlags.ALLOBJECTS );		
	    for ( int i = 0; i < geom.Count(); i++ )
		{
			view.Insert( geom[i] );
		}
	    if ( view.Count() > 0 ) 
	        return view;
		
	    return NULL;
	}	
};
