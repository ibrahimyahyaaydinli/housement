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
  Linking,
} from 'react-native';

//import database from '@react-native-firebase/database';

import IconHome from 'react-native-vector-icons/MaterialCommunityIcons';

import {styles} from '../style';
import {Button, TextInput} from 'react-native-paper';

import {readData, updateData} from './Database';

import {LocalNotification} from '../src/services/LocalPushController';
import DatePicker from 'react-native-date-picker';
import {PushNotificationScheduleObject} from 'react-native-push-notification';

import BackgroundJob from 'react-native-background-actions';

const sleepp = time =>
  new Promise(resolve => setTimeout(() => resolve(), time));

function handleOpenURL(evt) {
  console.log(evt.url);
  // do something with the url
}

Linking.addEventListener('url', handleOpenURL);

const Leds = props => {
  return (
    <View style={styles.sleepLightView}>
      <View style={styles.sleepLightElements}>
        <Text style={styles.sleepLightElementsText}>{props.statePartName}</Text>
      </View>
      <View style={styles.sleepLightElements}>
        <Text>
          <IconHome
            name={props.state ? 'led-on' : 'led-off'}
            color={props.state ? '#37A64E' : '#A63737'}
            size={50}
          />
        </Text>
      </View>
    </View>
  );
};

const Sleep = ({navigation}) => {
  let playing = BackgroundJob.isRunning();
  const [isGas, setGas] = useState();
  let toggle1 = readData('is_led_open/led_1').state_ops;
  let toggle2 = readData('is_led_open/led_2').state_ops;

  const [date, setDate] = useState(new Date());
  const [open, setOpen] = useState(false);

  const settedHours = readData('sleep/hours/state_ops');
  const settedMinutes = readData('sleep/minute/state_ops');

  {
    /*const handNot = () => {
    const currentTime = new Date();

    LocalNotification();
  };*/
  }
  const options = {
    taskName: 'Example',
    taskTitle: 'Housement ile daima güvendesiniz',
    taskDesc: 'uyku modu etkin değil',
    taskIcon: {
      name: 'ic_launcher',
      type: 'mipmap',
    },
    color: 'red',
    linkingURI: 'yourSchemeHere://chat/jane',
    parameters: {
      delay: 1000,
    },
  };
  const taskRandom = async taskData => {
    await new Promise(async resolve => {
      const {delay} = taskData;

      console.log(BackgroundJob.isRunning(), delay);
      let flag = 0;
      while (BackgroundJob.isRunning()) {
        const currentTime = new Date();
        if (currentTime.getMinutes() == settedMinutes && flag == 0) {
          console.log('merhaba');
          LocalNotification();
          updateData(false, 'is_led_open/led_1');
          updateData(false, 'is_led_open/led_2');
          await BackgroundJob.updateNotification({
            taskDesc: 'Uyku modu etkin',
          });

          flag = 1;
        }

        await sleepp(delay);
      }
    });
  };

  const toggleBackground = async () => {
    playing = !playing;
    if (playing) {
      try {
        console.log('Trying to start background service');
        await BackgroundJob.start(taskRandom, options);
        console.log('Successful start!');
      } catch (e) {
        console.log('Error', e);
      }
    }
  };

  const cancelBacground = async () => {
    if (playing) {
      Alert.alert(
        'Uyarı',
        'Arkaplanda çalışmayı durdurursanız yaptığınız işlemler devreye girmeyecektir',
        [
          {
            text: 'Cancel',
            onPress: () => console.log('Cancel Pressed'),
            style: 'cancel',
          },
          {
            text: 'OK',
            onPress: () => {
              BackgroundJob.stop();
              playing = false;
            },
          },
        ],
      );
    } else {
      Alert.alert('Uyarı', 'Arkaplan çalışma zaten kapalı');
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
            Sleep
          </Text>
        </View>
      </View>

      <Leds state={toggle1} statePartName="Salon" />
      <Leds state={toggle2} statePartName="Yatak Odası" />

      <View style={styles.dateView}>
        <Button
          style={{height: '100%', justifyContent: 'space-around', fontSize: 35}}
          labelStyle={{
            fontSize: 20,
            color: 'black',
            fontFamily: 'Questrial-Regular',
          }}
          title="Open"
          mode="elevated"
          color="#243A73"
          onPress={() => setOpen(true)}>
          zamanı ayarla
        </Button>
        <DatePicker
          modal
          mode="time"
          androidVariant="iosClone"
          open={open}
          date={date}
          onConfirm={date => {
            setOpen(false);
            setDate(date);
            updateData(date.getHours(), 'sleep/hours');
            updateData(date.getMinutes(), 'sleep/minute');
            toggleBackground();
          }}
          onCancel={() => {
            setOpen(false);
          }}
        />
      </View>

      <View style={styles.sleepDateTextView}>
        <Text style={{fontSize: 15}}>Mevcut Ayarlanmış Zaman</Text>
        <Text
          style={{
            fontSize: 35,
            fontFamily: 'Orbitron-Regular',
            color: '#06329A',
          }}>
          {10 > readData('sleep/hours/state_ops')
            ? '0' + readData('sleep/hours/state_ops')
            : readData('sleep/hours/state_ops')}
          :
          {10 > readData('sleep/minute/state_ops')
            ? '0' + readData('sleep/minute/state_ops')
            : readData('sleep/minute/state_ops')}
        </Text>
        <View>
          <TouchableHighlight
            style={{backgroundColor: 'yellow'}}
            onPress={cancelBacground}>
            <Text>Arkada çalışmayı devre dışı bırak</Text>
          </TouchableHighlight>
        </View>
      </View>
    </SafeAreaView>
  );
};

export default Sleep;
