import React from 'react';

import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
  Alert,
  Button,
  TouchableHighlight,
  TouchableOpacity,
} from 'react-native';

import {styles} from '../style';
import IconHome from 'react-native-vector-icons/MaterialCommunityIcons';
import Icon from 'react-native-vector-icons/Feather';
import LinearGradient from 'react-native-linear-gradient';
import {Avatar} from 'react-native-paper';
import {useEffect} from 'react';
import {readData} from './Database';

const Home = ({navigation}) => {
  const temp = readData('temperature');
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.avatarView}>
        <View style={styles.housementLogo}>
          <Text
            style={{
              fontSize: 30,
              color: '#34B3F1',
              fontFamily: 'SpaceMono-Regular',
              opacity: 0.4,
            }}>
            h o u s e m e n t
          </Text>
        </View>
        <View style={styles.housementLogo}>
          <Text style={{fontSize: 20, color: 'white'}}>
            İbrahim Yahya Aydınlı
          </Text>
        </View>
        <View style={styles.avatar}>
          <Avatar.Image size={100} source={require('../screens/indir.png')} />
        </View>
      </View>
      <View
        style={{
          justifyContent: 'center',
          flex: 1,

          width: '100%',
          alignItems: 'center',
        }}>
        <View style={styles.tempereture}>
          <View
            style={{
              height: '100%',
              width: '60%',
              justifyContent: 'space-around',
              alignItems: 'flex-end',
            }}>
            <Text
              style={{
                fontSize: 40,
                fontFamily: 'Orbitron-Bold',
                color: 'black',
              }}>
              {temp}
            </Text>
          </View>
          <View
            style={{
              height: '100%',
              width: '40%',
              justifyContent: 'space-around',
            }}>
            <Text style={{fontSize: 25}}>
              <IconHome name="temperature-celsius" size={55} color="black" />
            </Text>
          </View>
        </View>
      </View>
      <View style={styles.fourMenuView}>
        <TouchableOpacity
          style={{onPress: 'white'}}
          onPress={() => navigation.navigate('Lights')}>
          <View style={styles.view}>
            <IconHome name="lamps-outline" color={'#243A73'} size={50} />
            <Text style={{fontSize: 19}}>Lighting</Text>
          </View>
        </TouchableOpacity>

        <TouchableOpacity onPress={() => navigation.navigate('Gas')}>
          <View style={styles.view}>
            <IconHome name="chemical-weapon" color={'#243A73'} size={50} />

            <Text style={{fontSize: 19}}>Gas </Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress={() => navigation.navigate('Sleep')}>
          <View style={styles.view}>
            <IconHome name="sleep" color={'#243A73'} size={50} />
            <Text style={{fontSize: 19}}>Sleep </Text>
          </View>
        </TouchableOpacity>

        <TouchableOpacity onPress={() => navigation.navigate('BurglarAlarm')}>
          <View style={styles.view}>
            <IconHome name="security" color={'#243A73'} size={50} />

            <Text style={{fontSize: 19}}>House Protect</Text>
          </View>
        </TouchableOpacity>
      </View>
    </SafeAreaView>
  );
};

export default Home;
