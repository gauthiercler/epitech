package com.jcoinche.server;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Predicate;

public class RoomManager {

	private AtomicInteger	roomIdFactory;
	private ArrayList<Room> rooms;

	public RoomManager() {
		this.roomIdFactory = new AtomicInteger();
		this.rooms = new ArrayList<>();
	}

	public Room		createRoom() {
		Room		room = new Room(this.roomIdFactory.incrementAndGet());
		this.rooms.add(room);
		System.out.println("Created room w/ ID : " + Integer.toString(room.getId()));
		return room;
	}

	public ArrayList<Room>	getRooms() { return this.rooms; }

	public Room		getRoom(Room room) {
		return this.rooms.get(this.rooms.indexOf(room));
	}

	public Room		getRoomById(int id) {
		Predicate<Room>	predicate = room -> room.getId() == id;
		return this.rooms.stream().filter(predicate).findFirst().orElse(null);
	}

	public boolean	removeRoom(Room room) {
		System.out.println("Removed room w/ ID : " + Integer.toString(room.getId()));
		return rooms.remove(room);
	}

	public boolean	removeRoomById(int id) {
		Predicate<Room>	predicate = room -> room.getId() == id;
		return this.removeRoom(this.rooms.stream().filter(predicate).findFirst().orElse(null));
	}

	public Room		getRoomWithPlayer(Player player) {
		Predicate<Room>	predicate = room -> room.getPlayer(player) != null;
		return this.rooms.stream().filter(predicate).findFirst().orElse(null);
	}

	public Room		getAvailableRoom() {
		Predicate<Room> predicate = room -> room.getNbPlayers() < Room.maxPlayers;
		return this.rooms.stream().filter(predicate).findFirst().orElse(null);
	}
}
