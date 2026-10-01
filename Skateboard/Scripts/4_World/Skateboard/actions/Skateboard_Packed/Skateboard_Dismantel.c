class ActionDismantleSkateboardCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT);
	}
}
	
class ActionDismantleSkateboard: ActionContinuousBase
{
	static bool DismantleStopLinking = false;
	void ActionDismantleSkateboard()
	{

		
		m_CallbackClass	= ActionDismantleSkateboardCB;
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_StanceMask	= DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody 		= true;
		
		m_Text 			= "#disarm";

	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		
        Object targetObject = target.GetObject();
        if(targetObject)
        {            
                string selection = targetObject.GetActionComponentName( target.GetComponentIndex() );
                if ( selection == "dismantleboard" )
                {
                    return true;
                }            
        }
        
        return false;
    }
		
	override void OnStartAnimationLoopClient( ActionData action_data )
	{		
		DismantleStopLinking = true;
		
		//PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		
		super.OnStartAnimationLoopClient(action_data);	 
	}
	override void OnEndAnimationLoopClient( ActionData action_data ) //method called on finish main animation loop (before out animation part )
	{
		DismantleStopLinking = false;
		super.OnEndAnimationLoopClient(action_data);
	}
		
	
	override string GetText()
	{
		return "Dismantle Skateboard";
	}
	
	
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		Object targetObject = action_data.m_Target.GetObject();
		Object m_Object;

		vector offset = Vector(0,1,0);

		
		
		string name = "";
		Skateboard myboard = Skateboard.Cast( action_data.m_Target.GetObject() );
		if(myboard)
		{
			name = myboard.getpackedname();
			m_Object = GetGame().CreateObject( name, targetObject.GetPosition() + offset, false, false,false );	
			myboard.Delete();
		}
		
	}
	override void OnFinishProgressClient( ActionData action_data )
	{
		DismantleStopLinking = false;
		
		super.OnFinishProgressClient(action_data);
	}
	
	
	
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " dismantled " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName();
	}
}