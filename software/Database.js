import React, {useEffect, useState} from 'react';

import database from '@react-native-firebase/database';

const readData = read => {
  const [data, setData] = useState([]);
  const datRef = database().ref('/users/' + 'h123456789/' + read);
  useEffect(() => {
    datRef.on('value', snapshot => {
      {
        setData(snapshot.val());
      }
    });
  }, []);

  return data;
};

const updateData = (ops, opsId) => {
  database()
    .ref('/users/h123456789/' + opsId)
    .update({
      state_ops: ops,
    });
};

export {readData, updateData};
