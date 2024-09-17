#pragma once

namespace Extensions
{
    using namespace VWFC::PluginSupport;

    // ------------------------------------------------------------------------------------------------------
    class CPoly_EventSink : public VWTool_EventSink
    {
    public:
                            CPoly_EventSink(IVWUnknown* parent);
        virtual                ~CPoly_EventSink();

    public:
        virtual bool            DoSetUp(bool bRestore, const IToolModeBarInitProvider* pModeBarInitProvider);
        virtual void            DoSetDown(bool bRestore, const IToolModeBarInitProvider* pModeBarInitProvider);
        virtual void            MouseMove();
        virtual void            HandleComplete();
        virtual void            DoDoubleClick();
        virtual void            Draw(const IToolDrawProvider* pToolDrawProvider);
        virtual void            PointAdded();
        virtual void            OnInitXProperties(IToolPropertiesProvider *pPropsProvider);

    protected:
        void            ClearAllToolInteractiveObjects();
        void            UpdateToolInteractiveObjects();
    };

    // ------------------------------------------------------------------------------------------------------
    class CPoly : public VWExtensionTool
    {
        DEFINE_VWToolExtension;
    public:
        CPoly(CallBackPtr cbp);
        virtual                            ~CPoly();

    };
}
