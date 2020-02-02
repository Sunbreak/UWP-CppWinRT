#pragma once

#include "MainPage.g.h"

namespace winrt::UWP_CppWinRT::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher bluetoothLEWatcher{ nullptr };

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void button1_click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
        void button2_click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::UWP_CppWinRT::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
