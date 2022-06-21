import React, {useState, useEffect} from 'react';

import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
  TouchableHighlight,
  Switch,
  Alert,
  FlatList,
} from 'react-native';

import databaseL from '@react-native-firebase/database';

import IconHome from 'react-native-vector-icons/MaterialCommunityIcons';

import {styles} from '../style';
import {Button, TextInput} from 'react-native-paper';
import {readData, updateData} from './Database';

const Leds = props => {
  return (
    <View style={styles.lightsViewElements}>
      <View style={styles.lightsViewElementsItemsNameView}>
        <Text style={styles.lightsViewElementsItemsText}>
          {props.statePartName}
        </Text>
      </View>

      <TouchableHighlight
        style={styles.lightsViewElementsItems}
        onPress={() => {
          updateData(!props.state, props.stateName);
        }}
        underlayColor={!props.state ? '#37A64E' : '#A63737'}>
        <View>
          <IconHome
            name={props.state ? 'led-on' : 'led-off'}
            color={props.state ? '#37A64E' : '#A63737'}
            size={50}
          />
        </View>
      </TouchableHighlight>
    </View>
  );
};

const Lights = ({navigation}) => {
  const [isToggle, setToggle] = useState(false);

  let toggle1 = readData('is_led_open/led_1').state_ops;
  let toggle2 = readData('is_led_open/led_2').state_ops;

  return (
    <SafeAreaView>
      <View style={styles.forLightsView}>
        <View style={{}}>
          <Text
            style={{
              fontSize: 20,
              fontFamily: 'Questrial-Regular',
              color: 'white',

              opacity: 0.5,
            }}>
            housement
          </Text>
        </View>
        <View>
          <Text
            style={{
              fontSize: 40,
              fontFamily: 'Questrial-Regular',
              color: 'white',
            }}>
            lights
          </Text>
        </View>
      </View>
      <View style={styles.lightsView}>
        <Leds
          stateName="is_led_open/led_1"
          state={toggle1}
          statePartName="Salon"
        />
        <Leds
          stateName="is_led_open/led_2"
          state={toggle2}
          statePartName="Yatak Odası"
        />
      </View>
    </SafeAreaView>
  );
};

export default Lights;
