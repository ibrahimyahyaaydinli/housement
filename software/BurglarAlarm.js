import React, {useState, useEffect, Component} from 'react';

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
  Linking,
} from 'react-native';

import IconHome from 'react-native-vector-icons/MaterialCommunityIcons';

import {styles} from '../style';
import {Button, TextInput} from 'react-native-paper';

import {readData, updateData} from './Database';

import {LocalNotification} from '../src/services/LocalPushController';
import DatePicker from 'react-native-date-picker';
import {PushNotificationScheduleObject} from 'react-native-push-notification';

const BurglarAlarm = ({navigation}) => {
  const isAway = readData('is_away/state_ops');
  const outMode = () => {
    if (isAway) {
      updateData(false, 'is_away');
    } else {
      updateData(true, 'is_away');
    }
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
            Burglar Alarm
          </Text>
        </View>
      </View>
      <View style={{marginTop: 50, alignItems: 'center'}}>
        <TouchableHighlight
          style={{
            alignItems: 'center',
            width: '50%',
            backgroundColor: 'white',
          }}
          onPress={outMode}>
          <Text>
            <IconHome
              name="security"
              size={200}
              color={isAway ? 'green' : 'red'}
            />
          </Text>
        </TouchableHighlight>
      </View>
      <View></View>
    </SafeAreaView>
  );
};

export default BurglarAlarm;
