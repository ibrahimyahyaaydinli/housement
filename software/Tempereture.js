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

//import database from '@react-native-firebase/database';

import IconHome from 'react-native-vector-icons/MaterialCommunityIcons';

import {styles} from '../style';
//import {Button, TextInput} from 'react-native-paper';

import dataBase, {readData} from './Database';

const Tempereture = ({navigation}) => {
  const [isGas, setGas] = useState();

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
            tempereture
          </Text>
        </View>
      </View>

      <View style={styles.tempereture}>
        <View>
          <Text style={{fontSize: 25}}>Temperature</Text>
        </View>
        <View>
          <Text style={{fontSize: 25}}>{readData('temperature')}</Text>
        </View>
      </View>
    </SafeAreaView>
  );
};

export default Tempereture;
