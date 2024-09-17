#include "StdAfx.h"

#include "Poly.h"

using namespace VectorWorks::Filing;
using namespace Extensions;

namespace Extensions
{
    // --------------------------------------------------------------------------------------------------------
    static SToolDef        gToolDef = {
        /*ToolType*/                    eExtensionToolType_Default2DPath,
        /*ParametricName*/                "",
        /*PickAndUpdate*/                ToolDef::pickAndUpdate,
        /*NeedScreenPlane*/                ToolDef::doesntNeedScreenPlane,
        /*Need3DProjection*/            ToolDef::doesntNeed3DView,
        /*Use2DCursor*/                    ToolDef::use2DCursor,
        /*ConstrainCursor*/                ToolDef::constrainCursor,
        /*NeedPerspective*/                ToolDef::doesntNeedPerspective,
        /*ShowScreenHints*/                ToolDef::showScreenHints,
        /*NeedsPlanarContext*/            ToolDef::needsPlanarContext,
        /*Message*/                        {"CPoly", "message"},
        /*WaitMoveDistance*/            0,
        /*ConstraintFlags*/                0,
        /*BarDisplay*/                    kToolBarDisplay_XY,
        /*MinimumCompatibleVersion*/    900,
        /*Title*/                        {"InfraBek", "title"},
        /*Category*/                    {"InfraBek", "category"},
        /*HelpText*/                    {"CPoly", "help"},
        /*VersionCreated*/                16,
        /*VersoinModified*/                0,
        /*VersoinRetired*/                0,
        /*OverrideHelpID*/                " ",
        /*Icon Specifier*/                "ObjectExample/Images/CPoly.png",
        /*Cursor Specifier*/            ""
    };
}

// --------------------------------------------------------------------------------------------------------
// /*YOU MUST CHANGE THIS UUID if you copy this code*/    {DF0D9D08-1704-4c9c-B2BF-185a526267AA} {9f5baab8-f8bb-4006-8614-e92dd397536a}
IMPLEMENT_VWToolExtension(
    /*Extension class*/    CPoly,
    /*Event sink*/        CPoly_EventSink,
    /*Universal name*/    "[PP] Infra bekabeling (SDK)",
    /*Version*/            1,
    /*UUID*/            /*YOU MUST CHANGE THIS UUID if you copy this code*/    0x9f5baab8, 0xf8bb, 0x4006, 0x86, 0x14, 0xe9, 0x2d, 0xd3, 0x97, 0x53, 0x6a );

// --------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------
CPoly::CPoly(CallBackPtr cbp)
    : VWExtensionTool( cbp, gToolDef )
{
//    gSDK->AlertCritical("cpoly callback!");
    std::cout << "hello!!";
}

CPoly::~CPoly()
{
//    gSDK->AlertCritical("cpoly!");
}

// --------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------
CPoly_EventSink::CPoly_EventSink(IVWUnknown* parent)
    : VWTool_EventSink( parent )
{
    gSDK->AlertCritical("eventsinkparent!");
    std::cout << "hello!!";
}

void CPoly_EventSink::OnInitXProperties(IToolPropertiesProvider *pPropsProvider)
{
    gSDK->AlertCritical("init!");
    std::cout << "init!!";
}

CPoly_EventSink::~CPoly_EventSink()
{
    gSDK->AlertCritical("eventsik!");
    std::cout << "hello!!";
}

void CPoly_EventSink::PointAdded()
{
    gSDK->AlertCritical("pointadded");
    std::cout << "hello!!";
}

bool CPoly_EventSink::DoSetUp(bool bRestore, const IToolModeBarInitProvider* pModeBarInitProvider)
{
    gSDK->AlertCritical("hello!");
    std::cout << "hello!!";

    
    
    gSDK->AddPullDownMenuMode("aa");
    gSDK->AddPullDownMenuItem(1, "Water");
    gSDK->AddPullDownMenuItem(1, "16A Schuko");
    gSDK->AddPullDownMenuItem(1, "16A CEE");
    gSDK->AddPullDownMenuItem(1, "32A");
    gSDK->AddPullDownMenuItem(1, "63A");
    gSDK->AddPullDownMenuItem(1, "125A");
    gSDK->AddPullDownMenuItem(1, "Powerlock");

    return true;
}

void CPoly_EventSink::DoDoubleClick()
{
    gSDK->AlertCritical("ouble");
    std::cout << "hello!!";
}

void CPoly_EventSink::Draw(const IToolDrawProvider* pToolDrawProvider)
{
    gSDK->AlertCritical("draw");
    std::cout << "hello!!";
}

void CPoly_EventSink::DoSetDown(bool bRestore, const IToolModeBarInitProvider* pModeBarInitProvider)
{
    this->ClearAllToolInteractiveObjects();
}

void CPoly_EventSink::MouseMove()
{
    this->UpdateToolInteractiveObjects();
}

void CPoly_EventSink::HandleComplete()
{
    gSDK->AlertCritical("handlecomplete");
    std::cout << "hello!!";
//    gSDK->SupportUndoAndRemove();
//    gSDK->SetUndoMethod( kUndoSwapObjects );
//    gSDK->NameUndoEvent( TXResStr("CPoly", "ExtToolUndoEvent") );
//    
//    TXString sym_name("example_sym");
//    Handle h_sym_container = gSDK->CreateSymbolDefinition(sym_name);
//    if(h_sym_container)
//    {
//        gSDK->AddAfterSwapObject( h_sym_container );
//        WorldRect wr;
//        wr.Set(WorldPt(0.0, 0.0), WorldPt(500.0, 500.0));
//        Handle hrect = gSDK->CreateRectangle(wr);
//        gSDK->ResetObject(hrect);
//        gSDK->AddObjectToContainer(hrect, h_sym_container);
//        gSDK->ResetObject(h_sym_container);
//        VCOMPtr<IFileIdentifier> fileID( IID_FileIdentifier );
//        if (fileID) {
//            TXString full("C:\\MyProjects\\Test Files\\EmptyFile.vwx");
//            fileID->Set(full);
//            bool bool_out = false;
//            fileID->ExistsOnDisk(bool_out);
//            fileID->GetFileFullPath(full);
//            if(bool_out){
//                gSDK->ExportResource(h_sym_container, fileID, false);
//            }
//        }
//        
//        gSDK->AddBeforeSwapObject( h_sym_container );
//        gSDK->DeleteObject(h_sym_container);
//        gSDK->EndUndoEvent();
//        
//    }
//    else {
//        gSDK->UndoAndRemove();
//    }
//    
//    InternalIndex ind = gSDK->MaxClassID();
//    TXString cl_name;
//    for(int i = 0; i <= ind; i ++){
//        Handle hh = gSDK->InternalIndexToHandle(i);
//        if(hh){
//            short obj_type = gSDK->GetObjectTypeN(hh);
//            if(obj_type == kClassDefNode)
//            {
//                cl_name.Clear();
//                if(gSDK->ValidClass(i))
//                {
//                    gSDK->ClassIDToName(i, cl_name);
//                    if(cl_name.GetLength() > 0){
//                    }
//                }
//            }
//        }
//    }
}


void CPoly_EventSink::ClearAllToolInteractiveObjects()
{
    gSDK->AlertCritical("clearall");
    std::cout << "hello!!";
//    VectorWorks::IToolInteractiveDrawPtr toolInteractive;
//    gSDK->GetCurrToolInteractiveDraw( & toolInteractive );
//    if (toolInteractive)
//    {
//        toolInteractive->ClearObjects();
//    }
}

void CPoly_EventSink::UpdateToolInteractiveObjects()
{
    gSDK->AlertCritical("updatetool");
    std::cout << "hello!!";
//    VectorWorks::IToolInteractiveDrawPtr toolInteractive;
//    gSDK->GetCurrToolInteractiveDraw( & toolInteractive );
//    if ( toolInteractive )
//    {
//        size_t    ptCnt    = this->GetToolPointsCount();
//        if ( ptCnt > 1 )
//        {
//            VWPoint2D    currPt;
//            this->GetToolPtCurren2D( currPt );
//
//            VWLine2DObj    lineObj( toolInteractive->GetObject( kLineNode ) );
//            lineObj.SetLine( this->GetToolPt2D( 0 ), currPt );
//        }
//    }
}
