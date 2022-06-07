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

const Home = ({navigation}) => {
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.avatarView}>
        <View style={styles.housementLogo}>
          <Text
            style={{
              fontSize: 35,
              color: '#34B3F1',
              fontFamily: 'SpaceMono-Regular',
            }}>
            housement
          </Text>
        </View>
        <View style={styles.housementLogo}>
          <Text style={{fontSize: 20, color: 'white'}}>Yahya Aydınlı</Text>
        </View>
        <View style={styles.avatar}>
          <Avatar.Image size={100} source={require('../screens/indir.png')} />
        </View>
      </View>

      <View style={styles.fourMenuView}>
        <View style={styles.view}>
          <TouchableOpacity
            style={{onPress: 'white'}}
            onPress={() => navigation.navigate('Lights')}>
            <IconHome name="lamps-outline" color={'#243A73'} size={50} />
          </TouchableOpacity>
          <Text style={{fontSize: 19}}>Lighting</Text>
        </View>
        <View style={styles.view}>
          <TouchableOpacity onPress={() => navigation.navigate('Lights')}>
            <IconHome name="chemical-weapon" color={'#243A73'} size={50} />
          </TouchableOpacity>
          <Text style={{fontSize: 19}}>Gas </Text>
        </View>
        <View style={styles.view}>
          <TouchableOpacity onPress={() => navigation.navigate('Lights')}>
            <IconHome name="sleep" color={'#243A73'} size={50} />
          </TouchableOpacity>
          <Text style={{fontSize: 19}}>Sleep</Text>
        </View>
        <View style={styles.view}>
          <TouchableOpacity onPress={() => navigation.navigate('Tempereture')}>
            <IconHome name="temperature-celsius" color={'#243A73'} size={50} />
          </TouchableOpacity>
          <Text style={{fontSize: 19}}>Temp</Text>
        </View>
      </View>
    </SafeAreaView>
  );
};

export default Home;
