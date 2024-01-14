import { getFirebassApp } from "$lib/firebase";
import { getDatabase, ref, get } from "firebase/database";

/** @type {import('./$types').PageLoad} */
export async function load() {
	const app = getFirebassApp();
	const database = getDatabase(app);
	const sensors = ref(database, 'sensors');
	/** @type {number} */
	let temp1Live;
	/** @type {number} */
	let moisture1Live;
	/** @type {number} */
	let temp2Live;
	/** @type {number} */
	let moisture2Live;
	/** @type {number} */
	let temp3Live;
	/** @type {number} */
	let moisture3Live;
	const data = await get(sensors)
  temp1Live = data.val().temperature1;
  moisture1Live = data.val().moisture1;
  temp2Live = data.val().temperature2;
  moisture2Live = data.val().moisture2;
  temp3Live = data.val().temperature3;
  moisture3Live = data.val().moisture3;
  return {temp: [temp1Live, temp2Live, temp3Live], moisture: [moisture1Live, moisture2Live, moisture3Live]};
}
