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

const Lights = ({navigation}) => {
  {
  }

  const [isToggle, setToggle] = useState(false);

  useEffect(() => {
    databaseL()
      .ref('/users')
      .on('value', snapshot => {
        {
          setToggle(snapshot.val().is_led_open.isToggle);
        }
      });
  }, []);

  const updateData = () => {
    setToggle(!isToggle);

    databaseL().ref('/users/is_led_open').update({
      isToggle: isToggle,
    });
  };

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
      <View style={{alignItems: 'center'}}>
        <TouchableHighlight onPress={updateData}>
          <IconHome
            name={isToggle ? 'led-on' : 'led-off'}
            color={'blue'}
            size={50}
          />
        </TouchableHighlight>
      </View>
    </SafeAreaView>
  );
};

export default Lights;
