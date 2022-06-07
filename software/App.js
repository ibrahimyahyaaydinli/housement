import React from 'react';

import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
} from 'react-native';

import Icon from 'react-native-vector-icons/MaterialCommunityIcons';
import IconMa from 'react-native-vector-icons/Feather';

import {MyTheme} from './style';
import {styles} from './style';

import {
  NavigationContainer,
  DefaultTheme,
  DarkTheme,
} from '@react-navigation/native';
import {createNativeStackNavigator} from '@react-navigation/native-stack';
import {createBottomTabNavigator} from '@react-navigation/bottom-tabs';

import Home from './screens/Home';
import Lights from './screens/Lights';
import Login from './screens/Login';
import Settings from './screens/Settings';
import Tempereture from './screens/Tempereture';

const Stack = createNativeStackNavigator();

const Tabs = createBottomTabNavigator();

Tabs.na;

const TabsNavigator = () => (
  <Tabs.Navigator
    screenOptions={({route}) => ({
      tabBarIcon: ({focused, color, size}) => {
        return (
          <IconMa
            name={route.name === 'Home' ? 'home' : 'settings'}
            color={'blue'}
            size={size}
          />
        );
      },
    })}>
    <Tabs.Screen
      name="Home"
      component={Home}
      options={{headerShown: false, tabBarBadge: 3}}
    />
    <Tabs.Screen
      name="Settings"
      component={Settings}
      options={{headerShown: false}}
    />
  </Tabs.Navigator>
);

const App = () => {
  return (
    <NavigationContainer theme={MyTheme}>
      <Stack.Navigator
        initialRouteName="Home"
        screenOptions={{headerShown: false}}>
        <Stack.Screen name="Main" component={TabsNavigator} />

        <Stack.Screen name="Lights" component={Lights} />
        <Stack.Screen name="Tempereture" component={Tempereture} />
      </Stack.Navigator>
    </NavigationContainer>
  );
};

export default App;
export {TabsNavigator};
