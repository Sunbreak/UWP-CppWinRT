#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::Devices::Bluetooth::Advertisement;

namespace winrt::UWP_CppWinRT::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
        bluetoothLEWatcher = BluetoothLEAdvertisementWatcher();
        bluetoothLEWatcherReceivedToken = bluetoothLEWatcher.Received({ get_weak(), &MainPage::BluetoothLEWatcher_Received });
    }

    MainPage::~MainPage()
    {
        bluetoothLEWatcher.Received(bluetoothLEWatcherReceivedToken);
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::button1_click(IInspectable const&, RoutedEventArgs const&)
    {
        OutputDebugString(L"button1_click\n");
        bluetoothLEWatcher.Start();
    }

    void MainPage::button2_click(IInspectable const&, RoutedEventArgs const&)
    {
        OutputDebugString(L"button2_click\n");
        bluetoothLEWatcher.Stop();
    }
    
    void MainPage::BluetoothLEWatcher_Received(BluetoothLEAdvertisementWatcher sender, BluetoothLEAdvertisementReceivedEventArgs args)
    {
        auto lifetime = get_strong();
        
        OutputDebugString((L"Received " + std::to_wstring(args.BluetoothAddress()) + L"\n").c_str());
    }
}
