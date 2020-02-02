#pragma once

#include "MainPage.g.h"

namespace winrt::UWP_CppWinRT::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();
        ~MainPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void button1_click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
        void button2_click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

    private:
        Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher bluetoothLEWatcher{ nullptr };

        event_token bluetoothLEWatcherReceivedToken;
        void BluetoothLEWatcher_Received(
            Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher sender,
            Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs args
        );
    };
}

namespace winrt::UWP_CppWinRT::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
